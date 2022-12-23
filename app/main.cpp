#include <fmt/core.h>

#include "Puzzle/Puzzle.hpp"

#include <array>
#include <unordered_set>

constexpr PuzzleType puzzle{{
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9},

}};

int main(int argc[[maybe_unused]], char** argv[[maybe_unused]])
{
    Puzzle p{puzzle};
    bool isSolved{false};

    while(!isSolved)
    {
        for(std::size_t rowIdx = 0; rowIdx < SECTION_SIZE; rowIdx++)
        {
            const auto row = p.getRow(rowIdx);
            for(std::size_t colIdx = 0; colIdx < SECTION_SIZE; colIdx++)
            {
                const auto col = p.getCol(colIdx);
            }
        }
    }
    return 0;
}