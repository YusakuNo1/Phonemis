#pragma once

#include "constants.h"
#include "hmm_tagger.h"
#include "lexicon_phonemizer.h"

#include <phonemis/base/config.h>
#include <phonemis/base/language_pipeline.h>
#include <phonemis/base/phonemizer/hybrid_phonemizer.h>
#include <phonemis/base/tagger/hmm_tagger.h>
#include <phonemis/base/tokenizer/tokenizer.h>
#include <phonemis/utils/conversions.h>

#include <memory>

namespace phonemis::en {

class Pipeline : public LanguagePipeline {
public:
  explicit Pipeline(const Config& config)
      : LanguagePipeline(config),
        tokenizer_(&constants::tokenizer::kSpecialCharacters, &constants::tokenizer::kExceptions),
        phonemizer_(config.phonemizer) {
    // Setup PoS tagger if specified
    if (config.tagger.has_value()) {
      tagger_ = std::make_unique<en::HMMTagger>(*config.tagger);
    }
  }

  // Performs a middle stage of the pipeline - including phonemization.
  std::u32string process(const std::u32string& input) override {
    // 1. Tokenize
    auto tokens = tokenizer_.tokenize(input);

    // 2. Apply Part-of-Speech tags
    if (tagger_) {
      tagger_->tag(tokens);
    }

    // 3. Generate phonemes (Lexicon with Neural fallback)
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
  phonemizer::HybridPhonemizer<en::LexiconPhonemizer, phonemizer::nn::NeuralPhonemizer> phonemizer_;

  // Optional submodules
  std::unique_ptr<tagger::HMMTagger> tagger_ = nullptr;
};

} // namespace phonemis::en
