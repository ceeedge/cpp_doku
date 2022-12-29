cmake_minimum_required(VERSION 3.22)

project(CppDoku
        VERSION 0.0.0
        DESCRIPTION "A pseudo-sudoku solver"
        LANGUAGES CXX
)

include(FetchContent)

FetchContent_Declare(
  fmtlib
  GIT_REPOSITORY  https://github.com/fmtlib/fmt
  GIT_TAG a33701196adfad74917046096bf5a2aa0ab0bb50
)
FetchContent_MakeAvailable(fmtlib)

add_subdirectory(app)
add_subdirectory(src)