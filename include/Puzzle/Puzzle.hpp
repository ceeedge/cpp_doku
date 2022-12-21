#pragma once

// Third-Party Includes
// Local Includes
// System Includes
#include <array>
#include <cstddef>

// The row, col, and subgrid size
constexpr std::size_t SECTION_SIZE{9};

using Section = std::array<unsigned int, SECTION_SIZE>;
using PuzzleType = std::array<std::array<unsigned int, SECTION_SIZE>, SECTION_SIZE>;

// The puzzle consists of the following:
// 9 Rows, 9 Cols, and 9 Subgrids
class Puzzle final
{
public:
    Puzzle() = default;
    Puzzle(const PuzzleType& puzzle);

    Section getRow(unsigned int rowNum) const;
    Section getCol(unsigned int colNum) const;
    Section getSubgrid(unsigned int subgridNum);

    void loadPuzzle(const PuzzleType& puzzle);

private:
    PuzzleType m_puzzle{};
    Section m_row{};
    Section m_col{};
    Section m_subgrid{};
    unsigned int m_rowNum{};
    unsigned int m_colNum{};
    unsigned int m_subgridNum{};
    bool puzzleLoaded{false};
};