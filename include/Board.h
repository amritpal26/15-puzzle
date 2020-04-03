
#include <vector>

namespace puzzle {

enum Direction {Up, Right, Down, Left};

class Board {
private:
    std::vector<int> tiles;

    const int size;
    
    int position;

public:

    Board();

    std::vector<Direction> getMoves();

    void makeMove(Direction direction);

    bool isValidMove(Direction direction);

    void createNewBoard();

    void print();
};
}
