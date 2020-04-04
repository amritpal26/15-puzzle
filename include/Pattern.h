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

    // Number of cells greater than 0.
    int size;

    // Used to check the delta in index for a direction.
    int getDelta(Direction direction);


public:

    Pattern(std::vector<int> _cells);

    std::vector<int> getCells() const;

    int getSize() const;

    bool equals(const Pattern& other) const;

    bool isValidPermutation(int cellIndex, Direction direction);

    Pattern createPermutation(int cellIndex, Direction direction);
};
}

void print();

#endif