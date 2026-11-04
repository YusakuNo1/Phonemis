#pragma once

#include "types.h"

#include <verbalis/verbalizer.h>

#include <string>

namespace phonemis::processor {

// Rewrites text the way it's read aloud (Verbalis): numbers, dates, symbols and abbreviations become words.
using Preprocessor = verbalis::Verbalizer;

/**
 * The text as it's read aloud.
 * @param preprocessor the language's preprocessor.
 * @param text the text to preprocess.
 * @returns the preprocessed text.
 */
std::u32string preprocess(const Preprocessor& preprocessor, std::u32string_view text);

/**
 * The text as it's read aloud, with the span of the input each of its characters came from.
 * @param preprocessor the language's preprocessor.
 * @param text the text to preprocess.
 * @returns the preprocessed text and its sources: copied text maps to itself, and every character of a change to the
 * whole span it replaced.
 */
Preprocessed preprocess_with_sources(const Preprocessor& preprocessor, std::u32string_view text);

} // namespace phonemis::processor
