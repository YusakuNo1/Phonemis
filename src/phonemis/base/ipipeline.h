#pragma once

#include "processor/types.h"

#include <cstddef>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace phonemis {

// A whitespace-separated word of an input text, located in its phonemization.
// Offsets and lengths count UTF-32 code points.
struct PhonemizedWord {
  std::size_t offset;          // Offset of the word in the input text.
  std::size_t length;          // Length of the word in the input text.
  std::size_t phoneme_offset;  // Offset of the word's phonemes in the phonemization.
  std::size_t phoneme_length;  // Length of the word's phonemes.
};

// Phonemization of a text, together with the position of each of its words.
struct PhonemizedText {
  std::u32string phonemes;            // The same as a complete pipeline call returns.
  std::vector<PhonemizedWord> words;  // In input order; empty if they could not be matched.
};

// An interface which allows to dynamically resolve pipelines for various languages.
class IPipeline {
public:
  virtual ~IPipeline() = default;

  virtual std::u32string operator()(std::string_view text, 
                                    bool preprocess = true,
                                    bool postprocess = true);

  virtual std::u32string operator()(std::u32string_view text,
                                    bool preprocess = true,
                                    bool postprocess = true);

  virtual PhonemizedText phonemize_words(std::string_view text);

  virtual PhonemizedText phonemize_words(std::u32string_view text);

  // A processing parts to be implemented by derived classes.
  virtual std::u32string preprocess(const std::u32string& input) = 0;
  virtual std::u32string process(const std::u32string& input) = 0;
  virtual std::u32string postprocess(const std::u32string& input) = 0;

  /**
   * Performs a preprocessing stage of the pipeline, keeping the span of the input each character came from.
   * @returns std::nullopt if the pipeline can't trace them; phonemize_words then preprocesses each word alone instead.
   */
  virtual std::optional<processor::Preprocessed> preprocess_with_sources(const std::u32string& /*input*/) {
    return std::nullopt;
  }

private:
  /**
   * Locates the words of a text in its phonemization, from the source of each preprocessed character.
   * @param text the input text.
   * @param preprocessed the text, preprocessed with its sources.
   * @returns the phonemes, and one word for each whitespace-separated input word, or for input words that one change
   * covers (a phone number written in two parts); none if processing doesn't keep a slot for each preprocessed word.
   */
  PhonemizedText locate_words(std::u32string_view text, const processor::Preprocessed& preprocessed);
};

} // namespace phonemis