#pragma once

#include <cstddef>
#include <string>
#include <utility>
#include <vector>

namespace phonemis::processor {

// For each character of a preprocessed text, the range [first, second) of the input it came from.
// Characters inserted from nowhere, like the spaces between spelled-out words, have kNoSource (constants.h).
using SourceSpan = std::pair<std::size_t, std::size_t>;
using SourceSpans = std::vector<SourceSpan>;

// A preprocessed text, with the source of each of its characters.
struct Preprocessed {
  std::u32string text;
  SourceSpans sources;
};

} // namespace phonemis::processor
