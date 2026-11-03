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

## Repository Structure

```
phonemis/
├── data/                          # Bundled resources (one subdirectory per language)
├── src/
│   ├── phonemis/
│   │   ├── base/                  # Core API: Pipeline, IPipeline, Config, phonemizer, tokenizer
│   │   ├── lang/                  # Language-specific modules (en/, de/, fr/, …)
│   │   ├── protophone/            # Pure C++ neural model inference engine
│   │   ├── utils/                 # Conversions, string utilities, Unicode support
│   │   └── main.cpp               # The phonemis_runner CLI tool
│   └── third-party/               # Bundled header-only dependencies (xsimd)
├── scripts/                       # Build, test, and lint scripts; tools/ creates the data files
├── test/                          # The phonemis_test suite
├── third-party/
│   └── verbalis/                  # Verbalis (git submodule): numbers, dates, symbols as words
├── phonemis_sources.rb            # Source lists for builds without CMake
└── CMakeLists.txt
```

Every language folder under `data/` contains the resources needed for phonemization — a lexicon
JSON file (word-to-phoneme dictionary), a Protophone model weights file (`.bin`) for neural
inference, and optionally a tagger JSON file for part-of-speech disambiguation (English). Mandarin Chinese
has a lexicon and a word segmenter (`segmenter.json`) instead, which goes in `Config::tagger`.
These are the files you point to in `phonemizer::Config`.

## Installation

### Requirements
- **C++20** compiler
- **CMake** ≥ 3.21
- **xsimd** (bundled as a header-only library under `src/third-party/`)
- **[Verbalis](https://github.com/software-mansion-labs/Verbalis)** (a git submodule in `third-party/verbalis/`)

### Building the Library

Clone with the submodule:

```bash
git clone --recursive https://github.com/software-mansion-labs/Phonemis.git
```

In an existing clone, run `git submodule update --init`. Without the submodule, CMake fetches Verbalis v0.1.1 from
GitHub, and a parent project can provide its own `verbalis::verbalis` target instead.

The following commands build the package as a static library:

```bash
mkdir build
cd build
cmake ..
make
```

### Build Options

| Option | Default | Description |
|--------|---------|-------------|
| `-DBUILD_RUNNER=ON` | OFF | Builds the `phonemis_runner` CLI tool |
| `-DBUILD_TESTS=ON` | OFF | Builds the test suite |

### SIMD Acceleration

SIMD is configured automatically at build time:
- **x86_64 desktop** (non-Emscripten, non-Android, non-iOS): AVX2 + FMA are enabled if the
  compiler supports them (`-mavx2 -mfma`), accelerating Protophone's convolution and mixing
  stages.
- **ARM** (Android arm64-v8a, iOS arm64): NEON is implicitly available and used by xsimd with
  no extra flags.

### Building Without CMake

A build that compiles the sources directly, like a CocoaPods podspec, compiles Verbalis too. `phonemis_sources.rb`
lists the files and header search paths, so a podspec doesn't hardcode them:

```ruby
require_relative "third-party/phonemis/phonemis_sources"

phonemis = "third-party/phonemis" # The Phonemis checkout, relative to the podspec
s.source_files = PhonemisSources.source_files(phonemis) + [...]
s.exclude_files = PhonemisSources.exclude_files(phonemis) + [...]
header_search_paths = PhonemisSources.header_search_paths(phonemis).map { |p| "\"$(PODS_TARGET_SRCROOT)/#{p}\"" }
```

### Mobile Builds

Dedicated scripts are provided for cross-compiling:
- **Android** (`scripts/build_android.sh`): Produces `.a` libraries for the arm64-v8a and x86_64 ABIs. It reads
  the NDK path from `ANDROID_NDK_HOME` or `ANDROID_NDK`.
- **iOS** (`scripts/build_ios.sh`): Produces `.a` libraries for devices (arm64) and simulators (arm64, x86_64).

## Sample Usage

All lexicons and trained neural model weights are bundled in the `./data/` subdirectory, organized
by language code. The example below uses the English (US) resources:

```cpp
#include <phonemis/base/pipeline.h>
#include <phonemis/utils/conversions.h>
#include <iostream>

int main() {
    using namespace phonemis;

    phonemizer::Config phon_config;
    phon_config.lang = "en-us";
    phon_config.lexicon_filepath = "data/en-us/lexicon_full.json";
    phon_config.nn_model_filepath = "data/en-us/phonemizer_en_us.bin";

    Config config;
    config.lang = "en-us";
    config.phonemizer = phon_config;

    Pipeline pipeline(config);

    std::string text = "I love it! This is the best day of my entire life.";
    auto phonemes = pipeline(text);

    std::cout << "Text: " << text << "\n";
    std::cout << "Phonemes: " << utils::conversions::u32_to_utf8(phonemes) << "\n";

    return 0;
}
```

The `Pipeline::operator()` accepts both `std::string_view` (UTF-8) and `std::u32string_view`
(UTF-32), returning phonemes as `std::u32string`. Individual pipeline stages —
`preprocess()`, `process()`, `postprocess()` — are also exposed.

`Pipeline::phonemize_words()` returns the phonemes together with the position of each input word in them, for
example to highlight words as they're spoken:

```cpp
std::u32string text = U"He's 25 years old.";
PhonemizedText result = pipeline.phonemize_words(text);

for (const PhonemizedWord& word : result.words) {
    auto written = text.substr(word.offset, word.length);
    auto spoken = result.phonemes.substr(word.phoneme_offset, word.phoneme_length);
    // He's → hˌiz, 25 → twˈɛntifˈIv, years → jˈɪɹz, old. → ˈOld.
}
```

Offsets and lengths count UTF-32 code points. If the words can't be matched to the phonemes, `words` is empty.

### Customizing preprocessing

Before phonemization, [Verbalis](https://github.com/software-mansion-labs/Verbalis) rewrites the text the way it's
read aloud: character and whitespace normalization, abbreviations and web addresses, numbers, and symbols. Each step
can be turned off, and a language's own abbreviations and symbols can be extended or overridden:

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
| `numbers` | numbers, dates, money, units, ... | `$5` → *five dollars* |
| `symbols` | remaining symbols | `&` → *and* |
| `abbreviations`, `symbol_words` | extra readings, as UTF-8 | `{"™", "trademark"}` |

All steps are on by default, and always run in this order: normalize, trim, terms, numbers, symbols.

### CLI Runner

```bash
./build/phonemis_runner --lang en-us \
    --lexicon data/en-us/lexicon_full.json \
    --model data/en-us/phonemizer_en_us.bin \
    "Hello world"
```

## The Mechanics of Pronunciation

Phonemis combines three complementary phonemization strategies, selected per word to maximize
accuracy:

### Rule-based

A language-aware tokenizer segments text using configurable rules for words, punctuation, and
special characters. Before that, Verbalis verbalizes digits, dates, currencies, fractions, and
ordinals into their textual forms according to language-specific conventions (for example, German
"einundzwanzig" unit-before-tens order, comma decimal separator).

### Lexicon (lookup-based)

An O(1) dictionary lookup provides the fastest and most reliable phonemization. It is cheap, can
be prepared offline, and handles exception words like "read" (present vs. past tense) correctly.
Other languages can be extended by providing a lexicon JSON file.

### Neural (Protophone)

For words not found in the lexicon, a neural phonemizer takes over. **Protophone** is a pure
C++ CTC-based model with SIMD-accelerated inference via xsimd (AVX2+FMA on x86_64, NEON on ARM).

These strategies are combined through a **hybrid phonemizer**: the lexicon is tried first, and
the neural model serves as a fallback. Each level can be individually enabled or disabled via
configuration.

### Extending to a New Language

Phonemis is designed to be contribution-friendly. Its preprocessing comes from Verbalis, so a new language needs
Verbalis to support it first. Then it needs these files under `src/phonemis/lang/XX/`:

| File | Purpose | Requirement |
|------|---------|-------------|
| `constants.h` | Language-specific data: tokenizer special-character rules, and what else its phonemizer needs. | Mandatory |
| `pipeline.h` | Pipeline class extending `LanguagePipeline`, which preprocesses with a Verbalis `Verbalizer` for its language code. Orchestrates a tokenizer, and a `HybridPhonemizer<LexiconPhonemizer, NeuralPhonemizer>`. | Mandatory |
| Lexicon JSON / Protophone model | Word-to-phoneme mappings **or** trained neural model (`.bin`). | At least one required |

Then register the language in the factory method at `src/phonemis/base/pipeline.cpp`.

## License

The source code of Phonemis is released under the [MIT license](LICENSE). Some of the data in `data/` and the bundled
libraries in `src/third-party/` come from other projects under their own licenses: see
[THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md). In particular, the English part-of-speech tagger (`tagger.json`)
is derived from a corpus licensed for non-commercial use only, so leave out `Config::tagger` in commercial products.

## Community Discord

[Join the Software Mansion Community Discord](https://discord.swmansion.com) to chat about Phonemis or other Software
Mansion libraries.

## Phonemis is created by Software Mansion

Since 2012, [Software Mansion](https://swmansion.com) has been a software agency with experience in building web and
mobile apps. We are Core React Native Contributors and experts in dealing with all kinds of React Native issues. We can
help you build your next dream product – [Hire us](https://swmansion.com/contact/projects?utm_source=phonemis\&utm_medium=readme).

[![swm](https://logo.swmansion.com/logo?color=white\&variant=desktop\&width=150\&tag=phonemis-github "Software Mansion")](https://swmansion.com)
