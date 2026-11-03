#pragma once

#include <verbalis/verbalizer.h>

namespace phonemis::processor {

/**
 * Configuration of preprocessing, which Verbalis does: which steps run, and readings added to the language's own.
 * @details Every step is on by default: normalize, trim, terms, numbers, symbols. Added readings are UTF-8 pairs:
 * {.abbreviations = {{"approx.", "approximately"}}}. An alias rather than the module's own struct: the configuration
 * is Verbalis's, field for field.
 */
using Config = verbalis::Options;

} // namespace phonemis::processor
