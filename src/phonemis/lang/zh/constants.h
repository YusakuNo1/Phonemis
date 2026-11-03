#pragma once

// The Mandarin pipeline reproduces misaki's Kokoro v1.0 G2P (misaki.zh.ZHG2P without
// a frontend): numbers read by Verbalis (cn2an's verbalization), punctuation mapping, jieba
// word segmentation and pypinyin readings, the last two precomputed into the lexicon.
namespace phonemis::zh::constants {

// --- Character classes ---
namespace han {
  // Characters phonemized as Mandarin (CJK Unified Ideographs). Anything else passes
  // through unchanged.
  inline constexpr char32_t kFirst = U'\u4E00';
  inline constexpr char32_t kLast = U'\u9FFF';

  // jieba only segments up to this character; later ones stand as words of their own.
  inline constexpr char32_t kLastSegmentable = U'\u9FD5';

  constexpr bool is_han(char32_t c) { return c >= kFirst && c <= kLast; }
  constexpr bool is_segmentable(char32_t c) { return c >= kFirst && c <= kLastSegmentable; }
} // namespace han

} // namespace phonemis::zh::constants
