# Sources and header search paths of Phonemis, for a podspec that compiles it in place (React Native ExecuTorch does).
# README.md, "Building Without CMake", shows how a podspec uses them. `root` is the Phonemis checkout, relative to the
# podspec; Verbalis is the third-party/verbalis submodule.
module PhonemisSources
  def self.source_files(root)
    [
      "#{root}/src/**/*.{cpp,hpp,h}",
      "#{root}/third-party/verbalis/cpp/include/**/*.h",
      "#{root}/third-party/verbalis/cpp/src/**/*.{cpp,h}",
    ]
  end

  # The runner's entry point, which isn't part of the library
  def self.exclude_files(root)
    ["#{root}/src/phonemis/main.cpp"]
  end

  # Phonemis includes <phonemis/...> and <third-party/...> from src/, and bundled xsimd includes itself as xsimd/... from
  # src/third-party/; Verbalis includes <verbalis/...> from both of its folders
  def self.header_search_paths(root)
    [
      "#{root}/src",
      "#{root}/src/third-party",
      "#{root}/third-party/verbalis/cpp/include",
      "#{root}/third-party/verbalis/cpp/src",
    ]
  end
end
