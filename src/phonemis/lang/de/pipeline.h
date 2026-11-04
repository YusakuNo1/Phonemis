#pragma once

#include "constants.h"

#include <phonemis/base/config.h>
#include <phonemis/base/language_pipeline.h>
#include <phonemis/base/phonemizer/hybrid_phonemizer.h>
#include <phonemis/base/phonemizer/lexicon_phonemizer.h>
#include <phonemis/base/tokenizer/tokenizer.h>
#include <phonemis/utils/conversions.h>

#include <memory>

namespace phonemis::de {

class Pipeline : public LanguagePipeline {
public:
  explicit Pipeline(const Config& config)
      : LanguagePipeline(config),
        tokenizer_(&constants::tokenizer::kSpecialCharacters, &constants::tokenizer::kExceptions),
        phonemizer_(config.phonemizer) {}

  // Performs a middle stage of the pipeline - including phonemization.
  std::u32string process(const std::u32string& input) override {
    // 1. Tokenize
    auto tokens = tokenizer_.tokenize(input);

    // 2. Generate phonemes (Lexicon with Neural fallback)
    return phonemizer_.phonemize(tokens);
  }

  // Performs a postprocessing stage of the pipeline.
  std::u32string postprocess(const std::u32string& input) override {
    // No postprocessing
    return input;
  }

private:
  // Required submodules
  tokenizer::Tokenizer tokenizer_;
  phonemizer::HybridPhonemizer<phonemizer::LexiconPhonemizer, phonemizer::nn::NeuralPhonemizer> phonemizer_;
};

} // namespace phonemis::de