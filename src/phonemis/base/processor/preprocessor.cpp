#include "preprocessor.h"

#include <phonemis/utils/conversions.h>

namespace phonemis::processor {

std::u32string preprocess(const Preprocessor& preprocessor, std::u32string_view text) {
  // Verbalis takes and returns UTF-8
  return utils::conversions::utf8_to_u32(preprocessor.process(utils::conversions::u32_to_utf8(text)));
}

} // namespace phonemis::processor
