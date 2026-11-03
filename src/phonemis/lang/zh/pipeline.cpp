#include "constants.h"
#include "pipeline.h"

#include <phonemis/utils/conversions.h>

#include <vector>

namespace phonemis::zh {

namespace {
// The span of the input each character of the preprocessed text came from: copied text maps to itself,
// and every character of a change to the whole span it replaced
SourceSpans sources_of(const verbalis::Result& result, size_t input_size) {
  SourceSpans sources;
  size_t original = 0;
  for (const auto& change : result.changes) {
    for (; original < change.start; original++) {
      sources.push_back({original, original + 1});
    }
    SourceSpan source = change.start < change.end ? SourceSpan{change.start, change.end} : kNoSource;
    sources.insert(sources.end(), utils::conversions::utf8_to_u32(change.replacement).size(), source);
    original = change.end;
  }
  for (; original < input_size; original++) {
    sources.push_back({original, original + 1});
  }
  return sources;
}
} // namespace

Pipeline::Pipeline(const Config& config) : preprocessor_(config.lang, config.preprocessor) {
  if (config.phonemizer.lexicon_filepath.has_value()) {
    phonemizer_ = std::make_unique<zh::LexiconPhonemizer>(config.phonemizer);
  }
  if (config.tagger.has_value()) {
    segmenter_ = std::make_unique<Segmenter>(*config.tagger);
  }
}

std::u32string Pipeline::preprocess(const std::u32string& input) {
  return processor::preprocess(preprocessor_, input);
}

std::u32string Pipeline::process(const std::u32string& input) {
  return phonemize(input, nullptr, nullptr);
}

std::u32string Pipeline::postprocess(const std::u32string& input) {
  // No postprocessing
  return input;
}

std::u32string Pipeline::phonemize(std::u32string_view input, const SourceSpans* sources,
                                   SourceSpans* phoneme_sources) const {
  using constants::han::is_han;

  std::u32string result;
  auto append = [&](std::u32string_view text, SourceSpan source) {
    result += text;
    if (phoneme_sources) {
      phoneme_sources->resize(result.size(), source);
    }
  };

  for (size_t start = 0; start < input.size();) {
    bool han = is_han(input[start]);
    size_t end = start;
    while (end < input.size() && is_han(input[end]) == han) {
      end++;
    }

    auto run = input.substr(start, end - start);
    if (!han) {
      for (size_t i = start; i < end; i++) {
        append(input.substr(i, 1), sources ? (*sources)[i] : kNoSource);
      }
    } else if (phonemizer_) {
      auto words = segmenter_ ? segmenter_->segment(run) : std::vector{run};
      bool first = true;
      for (auto word : words) {
        auto phonemes = phonemizer_->phonemize_word(word);
        if (phonemes.empty()) {
          continue;
        }
        if (!first) {
          append(U" ", kNoSource);
        }

        SourceSpan source = kNoSource;
        if (sources) {
          size_t offset = word.data() - input.data();
          for (size_t i = offset; i < offset + word.size(); i++) {
            source = merge(source, (*sources)[i]);
          }
        }
        append(phonemes, source);
        first = false;
      }
    }
    start = end;
  }
  return result;
}

PhonemizedText Pipeline::phonemize_words(std::u32string_view text) {
  // Preprocessing with its changes, which keep the origin of each character of the result
  verbalis::Result preprocessed = preprocessor_.process_with_changes(utils::conversions::u32_to_utf8(text));
  std::u32string normalized = utils::conversions::utf8_to_u32(preprocessed.text);
  SourceSpans sources = sources_of(preprocessed, text.size());

  SourceSpans phoneme_sources;
  PhonemizedText result{.phonemes = postprocess(phonemize(normalized, &sources, &phoneme_sources))};

  // Each space-separated group of phonemes becomes a word, spanning the input characters
  // its phonemes came from. Groups that share input characters (a number spelled out as
  // several words) make one word.
  SourceSpan word_source = kNoSource;
  const auto& phonemes = result.phonemes;
  for (size_t start = 0; start < phonemes.size();) {
    if (phonemes[start] == U' ') {
      start++;
      continue;
    }
    size_t end = start;
    SourceSpan source = kNoSource;
    while (end < phonemes.size() && phonemes[end] != U' ') {
      source = merge(source, phoneme_sources[end++]);
    }

    if (source != kNoSource) {
      if (!result.words.empty() && source.first < word_source.second) {
        auto& word = result.words.back();
        word_source = merge(word_source, source);
        word.length = word_source.second - word_source.first;
        word.phoneme_length = end - word.phoneme_offset;
      } else {
        word_source = source;
        result.words.push_back({source.first, source.second - source.first, start, end - start});
      }
    }
    start = end;
  }

  return result;
}

} // namespace phonemis::zh
