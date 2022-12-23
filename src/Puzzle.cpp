// Third-Party Includes
#include <fmt/core.h>
// Local Includes
#include "Puzzle/Puzzle.hpp"
// System Includes
#include <algorithm>
#include <cassert>
#include <cstdlib>

Puzzle::Puzzle(const PuzzleType& puzzle)
{
    loadPuzzle(puzzle);
}

Section Puzzle::getRow(unsigned int rowNum) const
{
    return( [this, rowNum]()
    {
        Section rowCopy;
        for(std::size_t idx = 0; idx < SECTION_SIZE; idx++)
        {
            rowCopy[idx] = m_puzzle[rowNum][idx];
        }
        return rowCopy;
    }());
}


Section Puzzle::getCol(unsigned int colNum) const
{
    return( [this, colNum]()
    {
        Section colCopy;
        for(std::size_t idx = 0; idx < SECTION_SIZE; idx++)
        {
            colCopy[idx] = m_puzzle[idx][colNum];
        }
        return colCopy;
    }());
}

Section Puzzle::getSubgrid(unsigned int subgridNum) const
{
    return( [this, subgridNum] ()
    {
        Section subgridCopy;
        const auto subgrid = static_cast<std::size_t>(subgridNum);
        std::size_t startRowIdx;
        std::size_t startColIdx = 0;
        if(subgrid > 0 && subgrid < 4)
            startRowIdx = 0;
        else if(subgrid > 3 && subgrid < 7)
            startRowIdx = 3;
        else if(subgrid > 6 && subgrid < 10)
            startRowIdx = 6;
        const auto endRowIdx{startRowIdx+3};
        const auto endColIdx{startColIdx+3};
        unsigned int subgridIdx{0};
        for(std::size_t rowIdx = startRowIdx; rowIdx < endRowIdx; rowIdx++)
            for(std::size_t colIdx = 0; colIdx < endColIdx; colIdx++)
            {
                subgridCopy[subgridIdx] = m_puzzle[rowIdx][colIdx];
                subgridIdx++;
            }
        return subgridCopy;

    }());
}

void Puzzle::loadPuzzle(const PuzzleType& puzzle)
{
    for(std::size_t row = 0; row < SECTION_SIZE; row++)
        for(std::size_t col = 0; col < SECTION_SIZE; col++)
        m_puzzle[row][col] = puzzle[row][col];

}

void Puzzle::setCell(unsigned int rowNum, unsigned int colNum, unsigned int value)
{
    m_puzzle[rowNum][colNum] = value;
}

void Puzzle::print() const
{ 
    for(const auto& row : m_puzzle)
        for(const auto& element : row)
            fmt::print("{} ", element);
        fmt::print("\n");
}