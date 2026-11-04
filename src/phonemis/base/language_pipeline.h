#pragma once

#include "config.h"
#include "ipipeline.h"
#include "processor/preprocessor.h"

#include <optional>
#include <string>

namespace phonemis {

/**
 * A language's pipeline, whose preprocessing is Verbalis for the language's code.
 * @details A language fills in processing and postprocessing; the preprocessing stages are shared.
 */
class LanguagePipeline : public IPipeline {
public:
  // Performs a preprocessing stage of the pipeline.
  std::u32string preprocess(const std::u32string& input) override {
    return processor::preprocess(preprocessor_, input);
  }

  // Performs a preprocessing stage of the pipeline, keeping the source of each character of the result.
  std::optional<processor::Preprocessed> preprocess_with_sources(const std::u32string& input) override {
    return processor::preprocess_with_sources(preprocessor_, input);
  }

protected:
  explicit LanguagePipeline(const Config& config) : preprocessor_(config.lang, config.preprocessor) {}

  processor::Preprocessor preprocessor_;
};

} // namespace phonemis
