#pragma once

#include "types.h"

#include <algorithm>

namespace phonemis::processor {

// The smallest span covering both.
inline SourceSpan merge(SourceSpan a, SourceSpan b) {
  return {std::min(a.first, b.first), std::max(a.second, b.second)};
}

} // namespace phonemis::processor
