```aura width=800 height=416
<div style={{ position: 'relative', display: 'flex', flexDirection: 'column', width: '100%', height: '100%', background: '#0a1240', borderRadius: 20, overflow: 'hidden', padding: '40px 44px', fontFamily: 'Inter' }}>
  <style>{`
    @keyframes reveal { 0%, 8% { transform: translateX(0); } 45%, 92% { transform: translateX(639px); } 100% { transform: translateX(0); } }
    @keyframes drift-a { 0%, 100% { transform: translate(0, 0); } 50% { transform: translate(30px, -20px); } }
    @keyframes drift-b { 0%, 100% { transform: translate(0, 0); } 50% { transform: translate(-26px, 18px); } }
    @media (prefers-reduced-motion: reduce) { #orb0, #orb1, #cover0, #cover1, #cover2 { animation: none; } }
    #orb0 { animation: drift-a 12s ease-in-out infinite; }
    #orb1 { animation: drift-b 14s ease-in-out infinite; }
    #cover0 { animation: reveal 9s cubic-bezier(0.4, 0, 0.2, 1) infinite 0.0s backwards; }
    #cover1 { animation: reveal 9s cubic-bezier(0.4, 0, 0.2, 1) infinite 0.9s backwards; }
    #cover2 { animation: reveal 9s cubic-bezier(0.4, 0, 0.2, 1) infinite 1.8s backwards; }
  `}</style>
  <svg width="800" height="416" style={{ position: 'absolute', top: 0, left: 0 }}>
    <defs>
      <radialGradient id="g0"><stop offset="0%" stopColor="rgba(255,196,107,0.35)" /><stop offset="100%" stopColor="rgba(255,196,107,0)" /></radialGradient>
      <radialGradient id="g1"><stop offset="0%" stopColor="rgba(127,211,255,0.22)" /><stop offset="100%" stopColor="rgba(127,211,255,0)" /></radialGradient>
    </defs>
    <ellipse id="orb0" cx="700" cy="40" rx="260" ry="200" fill="url(#g0)" />
    <ellipse id="orb1" cx="60" cy="416" rx="240" ry="170" fill="url(#g1)" />
  </svg>
  <div style={{ display: 'flex', alignItems: 'flex-end', justifyContent: 'space-between', height: 92 }}>
    <div style={{ display: 'flex', flexDirection: 'column' }}>
      <span style={{ fontFamily: 'InterBold', fontSize: 56, color: '#ffffff', letterSpacing: -2, lineHeight: 1 }}>Phonemis</span>
      <span style={{ fontSize: 18, color: 'rgba(255,255,255,0.65)', marginTop: 12 }}>Text to phonemes, on device, for text-to-speech.</span>
    </div>
    <span style={{ fontSize: 12, color: 'rgba(255,255,255,0.4)', letterSpacing: 3, marginBottom: 4 }}>C++20</span>
  </div>
  <div style={{ display: 'flex', flexDirection: 'column', gap: 12, marginTop: 28 }}>
    <div style={{ display: 'flex', alignItems: 'center', height: 64, background: '#111a4d', borderRadius: 12, padding: '0 18px', border: '1px solid rgba(255,255,255,0.08)' }}>
      <span style={{ width: 58, fontSize: 12, color: 'rgba(255,255,255,0.45)', letterSpacing: 1 }}>en-us</span>
      <div style={{ display: 'flex', flexDirection: 'column' }}>
        <div style={{ display: 'flex', whiteSpace: 'pre', fontSize: 14, lineHeight: '18px' }}><span style={{ color: 'rgba(255,255,255,0.5)' }}>I paid </span><span style={{ color: '#ffc46b' }}>$49</span><span style={{ color: 'rgba(255,255,255,0.5)' }}> for </span><span style={{ color: '#ffc46b' }}>the FBI</span><span style={{ color: 'rgba(255,255,255,0.5)' }}> tickets.</span></div>
        <div style={{ display: 'flex', whiteSpace: 'pre', fontSize: 16, lineHeight: '22px', marginTop: 4 }}><span style={{ color: '#ffffff' }}>ˌI pˈAd </span><span style={{ color: '#7fd3ff' }}>fˈɔɹɾinˈIn dˈɑləɹz</span><span style={{ color: '#ffffff' }}> fɔɹ </span><span style={{ color: '#7fd3ff' }}>ði ˌɛfbˌiˈI</span><span style={{ color: '#ffffff' }}> tˈɪkəts.</span></div>
      </div>
    </div>
    <div style={{ display: 'flex', alignItems: 'center', height: 64, background: '#111a4d', borderRadius: 12, padding: '0 18px', border: '1px solid rgba(255,255,255,0.08)' }}>
      <span style={{ width: 58, fontSize: 12, color: 'rgba(255,255,255,0.45)', letterSpacing: 1 }}>de</span>
      <div style={{ display: 'flex', flexDirection: 'column' }}>
        <div style={{ display: 'flex', whiteSpace: 'pre', fontSize: 14, lineHeight: '18px' }}><span style={{ color: 'rgba(255,255,255,0.5)' }}>Ich habe </span><span style={{ color: '#ffc46b' }}>21</span><span style={{ color: 'rgba(255,255,255,0.5)' }}> Bücher.</span></div>
        <div style={{ display: 'flex', whiteSpace: 'pre', fontSize: 16, lineHeight: '22px', marginTop: 4 }}><span style={{ color: '#ffffff' }}>ɪç hˈɑːbə </span><span style={{ color: '#7fd3ff' }}>ˈInˌʊntʦvˌanʦɪç</span><span style={{ color: '#ffffff' }}> bˈyːçɜ.</span></div>
      </div>
    </div>
    <div style={{ display: 'flex', alignItems: 'center', height: 64, background: '#111a4d', borderRadius: 12, padding: '0 18px', border: '1px solid rgba(255,255,255,0.08)' }}>
      <span style={{ width: 58, fontSize: 12, color: 'rgba(255,255,255,0.45)', letterSpacing: 1 }}>pl</span>
      <div style={{ display: 'flex', flexDirection: 'column' }}>
        <div style={{ display: 'flex', whiteSpace: 'pre', fontSize: 14, lineHeight: '18px' }}><span style={{ color: 'rgba(255,255,255,0.5)' }}>Mam </span><span style={{ color: '#ffc46b' }}>3</span><span style={{ color: 'rgba(255,255,255,0.5)' }}> koty i psa.</span></div>
        <div style={{ display: 'flex', whiteSpace: 'pre', fontSize: 16, lineHeight: '22px', marginTop: 4 }}><span style={{ color: '#ffffff' }}>mˈam </span><span style={{ color: '#7fd3ff' }}>tʃˈɨ</span><span style={{ color: '#ffffff' }}> kˈɔtɨ ˈi psˈa.</span></div>
      </div>
    </div>
  </div>
  <svg width="800" height="416" style={{ position: 'absolute', top: 0, left: 0 }}>
    <defs>
      <clipPath id="clip0"><rect x="119" y="190" width="635" height="26" /></clipPath>
      <clipPath id="clip1"><rect x="119" y="266" width="635" height="26" /></clipPath>
      <clipPath id="clip2"><rect x="119" y="342" width="635" height="26" /></clipPath>
    </defs>
    <g clipPath="url(#clip0)"><g id="cover0" transform="translate(639, 0)"><rect x="119" y="190" width="635" height="26" fill="#111a4d" /><rect x="119" y="193" width="2" height="20" fill="#7fd3ff" /></g></g>
    <g clipPath="url(#clip1)"><g id="cover1" transform="translate(639, 0)"><rect x="119" y="266" width="635" height="26" fill="#111a4d" /><rect x="119" y="269" width="2" height="20" fill="#7fd3ff" /></g></g>
    <g clipPath="url(#clip2)"><g id="cover2" transform="translate(639, 0)"><rect x="119" y="342" width="635" height="26" fill="#111a4d" /><rect x="119" y="345" width="2" height="20" fill="#7fd3ff" /></g></g>
  </svg>
</div>
```
<p align="center">
  <a href="LICENSE"><img src="https://img.shields.io/badge/license-MIT-0a1240?style=for-the-badge" alt="MIT license"></a>
  <a href="https://discord.swmansion.com"><img src="https://img.shields.io/badge/Discord-join%20us-0a1240?style=for-the-badge&logo=discord&logoColor=white" alt="Join the Software Mansion Discord"></a>
</p>

## From Text to Sound

Phonemis is a high-performance C++ library for **Grapheme-to-Phoneme (G2P)** conversion. It
delivers universal **IPA phonemization** across many platforms with **no runtime dependencies**
(its text preprocessing, [Verbalis](https://github.com/software-mansion-labs/Verbalis), compiles into the library),
making it an ideal frontend for text-to-speech systems on desktop, mobile, and
embedded devices.

Currently supported languages:

*  🇺🇸 English (US) — `en-us`
*  🇬🇧 English (British) — `en-gb`
*  🇩🇪 German — `de`
*  🇫🇷 French — `fr`
*  🇪🇸 Spanish — `es`
*  🇮🇹 Italian — `it`
*  🇵🇱 Polish — `pl`
*  🇵🇹 Portuguese — `pt`
*  🇮🇳 Hindi — `hi`
*  🇨🇳 Mandarin Chinese — `zh`

## Quick start

Clone with the [Verbalis](https://github.com/software-mansion-labs/Verbalis) submodule, which reads text aloud
before phonemization, then build and run the tests:

```bash
git clone --recursive https://github.com/software-mansion-labs/Phonemis.git
cd Phonemis
cmake -S . -B build -DBUILD_TESTS=ON -DBUILD_RUNNER=ON
cmake --build build -j
./build/phonemis_test
```

To phonemize a sentence from the command line, run `phonemis_runner`:

```bash
./build/phonemis_runner --lang en-us \
    --lexicon data/en-us/lexicon_full.json \
    --model data/en-us/phonemizer_en_us.bin \
    --tagger data/en-us/tagger.json \
    "I paid \$49 for the FBI tickets."
```

```text
Preprocessed: I paid forty-nine dollars for the FBI tickets.
Output: ˌI pˈAd fˈɔɹɾinˈIn dˈɑləɹz fɔɹ ði ˌɛfbˌiˈI tˈɪkəts.
```

`--no <step>` turns off a preprocessing step: `normalize`, `trim`, `terms`, `numbers`, or `symbols`.

## Usage

Link the `phonemis` CMake target, then create a `Pipeline` for a language:

```cpp
#include <phonemis/base/pipeline.h>
#include <phonemis/utils/conversions.h>
#include <iostream>

int main() {
  using namespace phonemis;

  Pipeline pipeline(Config{
      .lang = "en-us",
      .tagger = tagger::Config{.data_filepath = "data/en-us/tagger.json"},
      .phonemizer = phonemizer::Config{
          .lang = "en-us",
          .lexicon_filepath = "data/en-us/lexicon_full.json",
          .nn_model_filepath = "data/en-us/phonemizer_en_us.bin",
      },
  });

  std::u32string phonemes = pipeline("I read it on 3 May.");
  std::cout << utils::conversions::u32_to_utf8(phonemes) << "\n";  // ˌI ɹˈid ɪt ˌɔn ðə θˈɜɹd ʌv mˈA.
}
```

A pipeline takes UTF-8 (`std::string_view`) or UTF-32 (`std::u32string_view`) text, and returns phonemes as
`std::u32string`. Its stages, `preprocess()`, `process()`, and `postprocess()`, are public too.

Each language's lexicon, neural model, and tagger are in `data/<code>/`. Mandarin Chinese has a lexicon
(`lexicon.json`) and a word segmenter (`segmenter.json`), which goes in `tagger`.

### Word positions

`phonemize_words` returns the phonemes together with the position of each input word in them. Offsets and lengths
count UTF-32 code points:

```cpp
std::u32string text = U"He's 25 years old.";
PhonemizedText result = pipeline.phonemize_words(text);

for (const PhonemizedWord& word : result.words) {
  auto written = text.substr(word.offset, word.length);
  auto spoken = result.phonemes.substr(word.phoneme_offset, word.phoneme_length);
  // He's → hˌiz, 25 → twˈɛntifˈIv, years → jˈɪɹz, old. → ˈOld.
}
```

A word keeps all the phonemes it's read as (`25` → *twenty five*), and the words that one reading covers, like
`40 %` → *forty percent*, come back as one. If the words can't be matched to the phonemes, `words` is empty.

### Preprocessing

Before phonemization, [Verbalis](https://github.com/software-mansion-labs/Verbalis) rewrites the text the way it's
read aloud. Each step can be turned off, and you can add to a language's abbreviations and symbol readings:

```cpp
Config config;
config.lang = "en-us";
config.phonemizer = phon_config;
config.preprocessor = {
    .symbols = false,                                // Keep "&", "+", ... as written
    .abbreviations = {{"approx.", "approximately"}}, // Added to the language's own
};
```

| Field | Step | Example |
|---|---|---|
| `normalize` | one form of each character | `’` → `'`, `„a“` → `"a"`, `a – b` → `a - b`, `…` → `...` |
| `trim` | whitespace normalization | `"  a   b , c"` → `"a b, c"` |
| `terms` | abbreviations, web addresses | `e.g.` → *for example*, `example.com` → *example dot com* |
| `numbers` | numbers, dates, money, units | `$5` → *five dollars* |
| `symbols` | remaining symbols | `&` → *and* |
| `abbreviations`, `symbol_words` | extra readings, as UTF-8 | `{"™", "trademark"}` |

All steps are on by default, and run in this order: normalize, trim, terms, numbers, symbols.

## How it works

```text
text ─▶ Verbalis ─▶ tokenizer ─▶ tagger ─▶ lexicon ─┬─▶ postprocessing ─▶ phonemes
                                (English)           │
                                             neural ┘ for words the lexicon lacks
```

1. **Preprocessing:** Verbalis reads numbers, dates, money, units, symbols, and abbreviations aloud, following each
   language's conventions, like German *einundzwanzig* for 21.
2. **Tokenization:** a language-aware tokenizer splits the text into words and punctuation.
3. **Tagging:** for English, an HMM tagger marks each word's part of speech, so *read* in "I read it yesterday" gets
   its past-tense pronunciation.
4. **Phonemization:** a hybrid phonemizer looks each word up in the lexicon first, and falls back to the neural model,
   Protophone, for words it doesn't find. Protophone is a small CTC model with SIMD inference through xsimd. With the
   tagger, the English lexicon reads *the* as *ði* or *ðə* by the next word's first sound: *ði FBI*, *ðə USA*.
5. **Postprocessing:** language-specific fixes to the phonemes, like Polish *ʑ* → *ʒ*.

## Building

| Option | Default | Description |
|---|---|---|
| `BUILD_TESTS` | `OFF` | Builds the `phonemis_test` test suite. `scripts/run_tests.sh` builds and runs it. |
| `BUILD_RUNNER` | `OFF` | Builds the `phonemis_runner` command-line tool. |

Phonemis needs a C++20 compiler and CMake 3.21 or later. It bundles its other dependency, xsimd, in `src/third-party/`.

### Verbalis

CMake finds Verbalis in this order:

1. a `verbalis::verbalis` target that the parent project already defines;
2. the `third-party/verbalis` submodule (in an existing clone, run `git submodule update --init`);
3. otherwise, the Verbalis `v0.1.1` release, fetched from GitHub.

### SIMD

On x86_64 desktop builds, CMake turns on AVX2 and FMA when the compiler supports them. On ARM (Android arm64-v8a,
iOS arm64), xsimd uses NEON with no extra flags.

### Android and iOS

- `scripts/build_android.sh` builds static libraries for `arm64-v8a` and `x86_64` into `output_android/`. It reads the
  NDK path from `ANDROID_NDK_HOME` or `ANDROID_NDK`.
- `scripts/build_ios.sh` builds static libraries for devices (`arm64`) and simulators (`arm64`, `x86_64`) into
  `output_ios/`. It runs on macOS with Xcode.

### Without CMake

A build that compiles the sources directly, like a CocoaPods podspec, compiles Verbalis too. `phonemis_sources.rb`
lists the source files and header search paths, so a podspec doesn't hardcode them:

```ruby
require_relative "third-party/phonemis/phonemis_sources"

phonemis = "third-party/phonemis" # The Phonemis checkout, relative to the podspec
s.source_files = PhonemisSources.source_files(phonemis) + [...]
s.exclude_files = PhonemisSources.exclude_files(phonemis) + [...]
header_search_paths = PhonemisSources.header_search_paths(phonemis).map { |p| "\"$(PODS_TARGET_SRCROOT)/#{p}\"" }
```

## Extending to a New Language

Phonemis is designed to be contribution-friendly. Its preprocessing comes from Verbalis, so a new language needs
Verbalis to support it first. Then it needs these files under `src/phonemis/lang/XX/`:

| File | Purpose | Requirement |
|------|---------|-------------|
| `constants.h` | Language-specific data: tokenizer special-character rules, and what else its phonemizer needs. | Mandatory |
| `pipeline.h` | Pipeline class extending `LanguagePipeline`, which preprocesses with a Verbalis `Verbalizer` for its language code. Orchestrates a tokenizer, and a `HybridPhonemizer<LexiconPhonemizer, NeuralPhonemizer>`. | Mandatory |
| Lexicon JSON / Protophone model | Word-to-phoneme mappings **or** trained neural model (`.bin`). | At least one required |

Then register the language in the factory method at `src/phonemis/base/pipeline.cpp`.

## License

Phonemis is licensed under [the MIT License](LICENSE). Some files in `data/` and `src/third-party/` come from other
projects under their own licenses, listed in [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md). In particular, the
English part-of-speech tagger (`tagger.json`) is derived from a corpus licensed for non-commercial use only, so leave
out `Config::tagger` in commercial products.

## Community Discord

[Join the Software Mansion Community Discord](https://discord.swmansion.com) to chat about Phonemis or other Software
Mansion libraries.

## Phonemis is created by Software Mansion

Since 2012, [Software Mansion](https://swmansion.com) has been a software agency with experience in building web and
mobile apps. We are Core React Native Contributors and experts in dealing with all kinds of React Native issues. We can
help you build your next dream product – [Hire us](https://swmansion.com/contact/projects?utm_source=phonemis\&utm_medium=readme).

[![swm](https://logo.swmansion.com/logo?color=white\&variant=desktop\&width=150\&tag=phonemis-github "Software Mansion")](https://swmansion.com)
