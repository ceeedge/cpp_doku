// Third-Party Includes
// Local Includes
#include "Puzzle/Puzzle.hpp"
// System Includes
#include <algorithm>
#include <cassert>

Puzzle::Puzzle(const PuzzleType& puzzle) : m_puzzle{puzzle} {}

Section Puzzle::getRow(unsigned int rowNum) const
{
    Section row{};
    std::copy(m_puzzle.at(rowNum).begin(), m_puzzle.at(rowNum).end(), row.begin());
    return row;
}


Section Puzzle::getCol(unsigned int colNum) const
{
    Section col{};
    std::copy(m_puzzle.at(colNum).begin(), m_puzzle.at(colNum).end(), col.begin());
}