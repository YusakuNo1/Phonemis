#pragma once

#include <phonemis/base/tokenizer/types.h>

#include <unordered_map>

namespace phonemis::hi::constants {

// --- Tokenization Rules ---
namespace tokenizer {
  using ::phonemis::tokenizer::split::Rule;
  using ::phonemis::tokenizer::split::Exceptions;

  inline const std::unordered_map<char32_t, Rule> kSpecialCharacters = {
    {U'\'', Rule::KEEP_WITH_RIGHT},
    {U'-',  Rule::TOTAL_DIVIDE},
    {U'.',  Rule::TOTAL_DIVIDE},
    {U':',  Rule::TOTAL_DIVIDE},
    // Devanagari combining marks: keep them inside words.
    {U'\u0900', Rule::TOTAL_JOIN}, // INVERTED CANDRABINDU
    {U'\u0901', Rule::TOTAL_JOIN}, // CANDRABINDU
    {U'\u0902', Rule::TOTAL_JOIN}, // ANUSVARA
    {U'\u0903', Rule::TOTAL_JOIN}, // VISARGA
    {U'\u093A', Rule::TOTAL_JOIN}, // VOWEL SIGN OE
    {U'\u093B', Rule::TOTAL_JOIN}, // VOWEL SIGN OOE
    {U'\u093C', Rule::TOTAL_JOIN}, // NUKTA
    {U'\u093E', Rule::TOTAL_JOIN}, // VOWEL SIGN AA
    {U'\u093F', Rule::TOTAL_JOIN}, // VOWEL SIGN I
    {U'\u0940', Rule::TOTAL_JOIN}, // VOWEL SIGN II
    {U'\u0941', Rule::TOTAL_JOIN}, // VOWEL SIGN U
    {U'\u0942', Rule::TOTAL_JOIN}, // VOWEL SIGN UU
    {U'\u0943', Rule::TOTAL_JOIN}, // VOWEL SIGN VOCALIC R
    {U'\u0944', Rule::TOTAL_JOIN}, // VOWEL SIGN VOCALIC RR
    {U'\u0945', Rule::TOTAL_JOIN}, // VOWEL SIGN CANDRA E
    {U'\u0946', Rule::TOTAL_JOIN}, // VOWEL SIGN SHORT E
    {U'\u0947', Rule::TOTAL_JOIN}, // VOWEL SIGN E
    {U'\u0948', Rule::TOTAL_JOIN}, // VOWEL SIGN AI
    {U'\u0949', Rule::TOTAL_JOIN}, // VOWEL SIGN CANDRA O
    {U'\u094A', Rule::TOTAL_JOIN}, // VOWEL SIGN SHORT O
    {U'\u094B', Rule::TOTAL_JOIN}, // VOWEL SIGN O
    {U'\u094C', Rule::TOTAL_JOIN}, // VOWEL SIGN AU
    {U'\u094D', Rule::TOTAL_JOIN}, // VIRAMA
    {U'\u094E', Rule::TOTAL_JOIN}, // VOWEL SIGN PRISHTHAMATRA E
    {U'\u094F', Rule::TOTAL_JOIN}, // VOWEL SIGN AW
    {U'\u0951', Rule::TOTAL_JOIN}, // STRESS SIGN UDATTA
    {U'\u0952', Rule::TOTAL_JOIN}, // STRESS SIGN ANUDATTA
    {U'\u0953', Rule::TOTAL_JOIN}, // GRAVE ACCENT
    {U'\u0954', Rule::TOTAL_JOIN}, // ACUTE ACCENT
    {U'\u0955', Rule::TOTAL_JOIN}, // VOWEL SIGN CANDRA E
    {U'\u0956', Rule::TOTAL_JOIN}, // VOWEL SIGN UE
    {U'\u0957', Rule::TOTAL_JOIN}, // VOWEL SIGN UUE
    {U'\u0962', Rule::TOTAL_JOIN}, // VOWEL SIGN VOCALIC L
    {U'\u0963', Rule::TOTAL_JOIN}  // VOWEL SIGN VOCALIC LL
  };

  inline const Exceptions kExceptions = {};
} // namespace tokenizer

} // namespace phonemis::hi::constants