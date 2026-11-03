#include "constants.h"
#include "preprocessor.h"

#include <phonemis/utils/conversions.h>

#include <stdexcept>

namespace phonemis::processor {

std::u32string preprocess(const Preprocessor& preprocessor, std::u32string_view text) {
  // Verbalis takes and returns UTF-8. It throws only on a bug of its own; the text is then read as written, since
  // phonemization never throws
  try {
    return utils::conversions::utf8_to_u32(preprocessor.process(utils::conversions::u32_to_utf8(text)));
  } catch (const std::logic_error&) {
    return std::u32string{text};
  }
}

Preprocessed preprocess_with_sources(const Preprocessor& preprocessor, std::u32string_view text) {
  // On a bug of Verbalis, as in preprocess(), the text is read as written: no changes, so each character is its own source
  verbalis::Result result;
  try {
    result = preprocessor.process_with_changes(utils::conversions::u32_to_utf8(text));
  } catch (const std::logic_error&) {
    result = {.text = utils::conversions::u32_to_utf8(text)};
  }
  Preprocessed preprocessed{.text = utils::conversions::utf8_to_u32(result.text)};
  preprocessed.sources.reserve(preprocessed.text.size());

  // Changes are in order and count code points of the input, like the indices of a UTF-32 string
  std::size_t original = 0;
  for (const auto& change : result.changes) {
    for (; original < change.start; original++) {
      preprocessed.sources.push_back({original, original + 1});
    }
    SourceSpan source = change.start < change.end ? SourceSpan{change.start, change.end} : kNoSource;
    preprocessed.sources.insert(preprocessed.sources.end(), utils::conversions::utf8_to_u32(change.replacement).size(),
                                source);
    original = change.end;
  }
  for (; original < text.size(); original++) {
    preprocessed.sources.push_back({original, original + 1});
  }
  return preprocessed;
}

} // namespace phonemis::processor
