#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <algorithm>
#include "Board.h"

using puzzle::Direction;

namespace database {
class Pattern {

private:
    // stores the pattern data cells.
    std::vector<int> cells;

    // Used to check the delta in index for a direction.
    int getDelta(Direction direction);

    // creates a permutation in the specified direction by moving the 
    // zero cell in direction.
    Pattern createPermutation(int cellIndex, Direction direction);

    // Checks if we can create a new permutation in a direction.
    bool isValidPermutation(int cellIndex, Direction direction);

public:
    Pattern();

    Pattern(std::vector<int> _cells);

    // int moves.
    int moves;
    
    // compares the current pattern with the other pattern
    bool equals(const Pattern& other) const;

    // Return a list of all reachable patterns from the current pattern.
    std::vector<Pattern> getAllReachablePatterns(const std::vector<int>& tiles); 

    static std::string getId(const std::vector<int>& tiles, const std::vector<int>& cells);

    std::vector<int> getCells() const;
};
}

void print();

#endif