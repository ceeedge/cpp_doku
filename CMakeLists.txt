cmake_minimum_required(VERSION 3.25)

project(CppDoku
        VERSION 0.0.0
        DESCRIPTION "A pseudo-sudoku solver"
        LANGUAGES CXX
)


find_package(fmt REQUIRED)

add_subdirectory(app)
add_subdirectory(src)