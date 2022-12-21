set(HEADER_LIST
${CMAKE_SOURCE_DIR}/include/Puzzle/Puzzle.hpp
)

add_library(game
    Puzzle.cpp
)

target_include_directories(game PUBLIC ../include)

target_link_libraries(game
PRIVATE
    fmt::fmt
)