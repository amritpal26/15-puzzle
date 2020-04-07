#pragma once

#include "PatternDatabase.h"

#include <vector>

using database::PatternDatabase;
using database::Direction;

namespace puzzle {
class Board {
private:
    std::vector<int> tiles;

    const int size;
    
    int position;

    const PatternDatabase& database;

public:

    Board(std::vector<int> tiles, const PatternDatabase& _database);

    std::vector<Direction> getMoves();
    
    std::vector<Direction> getMoves(Direction prevMove);

    void makeMove(Direction direction);

    void undoMove(Direction direction);

    bool isValidMove(Direction direction) const;

    void createNewBoard();

    void print();

    int getHeuristic();
};
}
