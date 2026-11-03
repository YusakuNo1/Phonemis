#include "ipipeline.h"
#include "processor/constants.h"
#include "processor/spans.h"

#include <phonemis/utils/conversions.h>
#include <phonemis/utils/unicode.h>

#include <algorithm>
#include <limits>
#include <utility>

namespace phonemis {

namespace {

// [begin, end) spans of a text, one per word or slot
using Spans = std::vector<std::pair<std::size_t, std::size_t>>;

// The span of each whitespace-separated word
Spans word_spans(std::u32string_view text) {
  Spans spans;
  spans.reserve(std::count(text.begin(), text.end(), U' ') + 1);
  for (std::size_t start = 0; start < text.size();) {
    if (utils::unicode::isspace(text[start])) {
      start++;
      continue;
    }
    std::size_t end = start;
    while (end < text.size() && !utils::unicode::isspace(text[end])) {
      end++;
    }
    spans.push_back({start, end});
    start = end;
  }
  return spans;
}

// The span of each space-separated slot, empty ones included: " a b" -> [0,0) [1,2) [3,4)
Spans slot_spans(std::u32string_view text) {
  Spans spans;
  spans.reserve(std::count(text.begin(), text.end(), U' ') + 1);
  std::size_t begin = 0;
  for (std::size_t i = 0; i <= text.size(); i++) {
    if (i == text.size() || text[i] == U' ') {
      spans.push_back({begin, i});
      begin = i + 1;
    }
  }
  return spans;
}

// The input word each slot comes from, and the input words that join the word before them: a change spanning several
// input words, like a phone number written in two parts (02522 88380), makes them one located word
struct SlotOwners {
  std::vector<std::size_t> owner; // For each slot, the input word it comes from
  std::vector<bool> joined;       // For each input word, whether it belongs to the word before it
};

SlotOwners own_slots(const Spans& words, const Spans& spoken, const processor::SourceSpans& sources) {
  SlotOwners owners{.owner = std::vector<std::size_t>(spoken.size()), .joined = std::vector<bool>(words.size(), false)};
  std::size_t last_owned = 0; // The last input word a slot came from
  for (std::size_t slot = 0; slot < spoken.size(); slot++) {
    processor::SourceSpan source = processor::kNoSource;
    for (std::size_t i = spoken[slot].first; i < spoken[slot].second; i++) {
      source = processor::merge(source, sources[i]);
    }

    // 1. Text inserted from nowhere belongs to the word before
    if (source == processor::kNoSource) {
      owners.owner[slot] = last_owned;
      continue;
    }

    // 2. The first input word ending after the source starts, and the last one starting before it ends
    std::size_t first = 0;
    while (first + 1 < words.size() && words[first].second <= source.first) {
      first++;
    }
    std::size_t last = first;
    while (last + 1 < words.size() && words[last + 1].first < source.second) {
      last++;
    }

    // 3. Out of order (before the last owned word): join back to it
    if (first < last_owned) {
      last = std::max(last, last_owned);
    }
    for (std::size_t word = first + 1; word <= last; word++) {
      owners.joined[word] = true;
    }
    owners.owner[slot] = first;
    last_owned = last;
  }
  return owners;
}

} // namespace

std::u32string IPipeline::operator()(std::string_view text,
                                     bool preprocess_flag,
                                     bool postprocess_flag) {
  return operator()(utils::conversions::utf8_to_u32(text), preprocess_flag, postprocess_flag);
}

std::u32string IPipeline::operator()(std::u32string_view text,
                                     bool preprocess_flag,
                                     bool postprocess_flag) {
  std::u32string result{text};

  if (preprocess_flag) {
    result = preprocess(result);
  }

  result = process(result);

  if (postprocess_flag) {
    result = postprocess(result);
  }

  return result;
}

PhonemizedText IPipeline::phonemize_words(std::string_view text) {
  return phonemize_words(utils::conversions::utf8_to_u32(text));
}

PhonemizedText IPipeline::phonemize_words(std::u32string_view text) {
  // With the source of each preprocessed character, the words are located exactly
  if (auto preprocessed = preprocess_with_sources(std::u32string{text})) {
    return locate_words(text, *preprocessed);
  }

  // Preprocessing can spell a word out as several (numbers, abbreviations,
  // symbols, web addresses), so each word is preprocessed alone to count them.
  // Processing then turns each preprocessed word into one space-separated group
  // of phonemes.
  std::u32string normalized = preprocess(std::u32string{text});
  PhonemizedText result{.phonemes = postprocess(process(normalized))};

  std::vector<std::size_t> group_lengths{0};
  for (char32_t c : result.phonemes) {
    if (c == U' ') {
      group_lengths.push_back(0);
    } else {
      group_lengths.back()++;
    }
  }

  std::size_t group = 0;
  std::size_t phoneme_offset = 0;
  for (auto [start, end] : word_spans(text)) {
    auto word = text.substr(start, end - start);
    std::size_t count = word_spans(preprocess(std::u32string{word})).size();

    std::size_t phoneme_length = count > 0 ? count - 1 : 0;  // Separating spaces.
    for (std::size_t i = group; i < group + count && i < group_lengths.size(); i++) {
      phoneme_length += group_lengths[i];
    }

    result.words.push_back({start, end - start, phoneme_offset, phoneme_length});
    if (count > 0) {
      phoneme_offset += phoneme_length + 1;
    }
    group += count;
  }

  // A number spelled out differently on its own than in context would shift
  // every word after it, so a mismatch drops the words rather than misplace them.
  if (group != word_spans(normalized).size() || group != group_lengths.size()) {
    result.words.clear();
  }

  return result;
}

PhonemizedText IPipeline::locate_words(std::u32string_view text, const processor::Preprocessed& preprocessed) {
  PhonemizedText result{.phonemes = postprocess(process(preprocessed.text))};
  Spans words = word_spans(text);
  Spans spoken = word_spans(preprocessed.text);
  Spans slots = slot_spans(result.phonemes);

  // Processing turns each preprocessed word into one space-separated slot of phonemes, empty for a word it drops (a
  // lone /). Otherwise no word is located; the counting fallback relies on the same thing.
  if (words.empty() || spoken.size() != slots.size() || preprocessed.sources.size() != preprocessed.text.size()) {
    return result;
  }

  // 1. The input word of each slot
  auto [owner, joined] = own_slots(words, spoken, preprocessed.sources);

  // 2. One located word per input word, or per run of joined input words
  std::vector<std::size_t> located_of(words.size());
  for (std::size_t word = 0; word < words.size(); word++) {
    if (word == 0 || !joined[word]) {
      result.words.push_back({.offset = words[word].first});
    }
    auto& located = result.words.back();
    located.length = words[word].second - located.offset;
    located_of[word] = result.words.size() - 1;
  }

  // 3. The slots of each located word: its first one, and its first and last with phonemes
  constexpr std::size_t kNone = std::numeric_limits<std::size_t>::max();
  struct LocatedSlots {
    std::size_t first = kNone;
    std::size_t first_spoken = kNone;
    std::size_t last_spoken = kNone;
  };
  std::vector<LocatedSlots> located_slots(result.words.size());
  for (std::size_t slot = 0; slot < slots.size(); slot++) {
    auto& located = located_slots[located_of[owner[slot]]];
    located.first = std::min(located.first, slot);
    if (slots[slot].first < slots[slot].second) {
      located.first_spoken = std::min(located.first_spoken, slot);
      located.last_spoken = slot;
    }
  }

  // 4. A word spans its slots with phonemes; one with only empty slots sits at its first slot, and one without any (a
  // word preprocessing removed) where the phonemes after the words before it start
  std::size_t next_phoneme = 0;
  for (std::size_t located = 0; located < result.words.size(); located++) {
    auto [first, first_spoken, last_spoken] = located_slots[located];
    if (first_spoken != kNone) {
      result.words[located].phoneme_offset = slots[first_spoken].first;
      result.words[located].phoneme_length = slots[last_spoken].second - slots[first_spoken].first;
      next_phoneme = std::min(slots[last_spoken].second + 1, result.phonemes.size());
    } else {
      result.words[located].phoneme_offset = first != kNone ? slots[first].first : next_phoneme;
    }
  }

  return result;
}

} // namespace phonemis
