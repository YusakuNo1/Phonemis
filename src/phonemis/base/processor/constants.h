#pragma once

#include "types.h"

#include <cstddef>
#include <limits>

namespace phonemis::processor {

// The source of a character inserted from nowhere: it covers no input, and merging with it changes nothing.
inline constexpr SourceSpan kNoSource = {std::numeric_limits<std::size_t>::max(), 0};

} // namespace phonemis::processor
