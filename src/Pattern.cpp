#include "../include/Pattern.h"
#include <iostream>

using database::Pattern;


Pattern::Pattern(std::vector<int> _cells) :
        cells(_cells),
        size(cells.size())
{
}

std::vector<int> 
Pattern::getCells() const {
    return cells;
}

int
Pattern::getSize() const {
    return size;
}

bool
Pattern::equals(const Pattern& other) const {
    return std::equal(cells.begin(), cells.end(), other.getCells().end());
}

bool 
Pattern::isValidPermutation(int cellIndex, Direction direction){
    if (cells[cellIndex] == 0)
        return false;
    else if(direction == Direction::Right && ((cellIndex+1) % 4) == 0 && cells[cellIndex+1] == 0)
        return true;
    else if(direction == Direction::Left && ((cellIndex-1) % 4) == 0 && cells[cellIndex-1] == 0)
        return true;
    else if(direction == Direction::Up && cellIndex > 3 && cells[cellIndex-4] == 0)
        return true;
    else if (direction == Direction::Down && cellIndex < 12 && cells[cellIndex+4] == 0)
        return true;
    
    return false;
}

Pattern
Pattern::createPermutation(int cellIndex, Direction direction){
    std::vector<int> permutationCells(cells.size());
    std::copy(cells.begin(), cells.end(), permutationCells.begin());

    //make move to permutation.
    int newCellIndex = cellIndex + getDelta(direction);
    permutationCells[newCellIndex] = permutationCells[cellIndex];
    permutationCells[cellIndex] = 0;

    Pattern pattern = {permutationCells};
    return pattern;
}

int 
Pattern::getDelta(Direction direction){
    switch(direction){
        case Direction::Up:
            return -4;
        case Direction::Down:
            return 4;
        case Direction::Right:
            return 1;
        case Direction::Left:
            return -1;
    }
    return 0;
}

// void
// Pattern::print(){
//     std::cout << cells[0] << " | " << cells[1] << " | " << cells[2] << " | " << cells[3] << std::endl;  
//     std::cout << cells[4] << " | " << cells[5] << " | " << cells[6] << " | " << cells[7] << std::endl;  
//     std::cout << cells[8] << " | " << cells[9] << " | " << cells[10] << " | " << cells[11] << std::endl;  
//     std::cout << cells[12] << " | " << cells[13] << " | " << cells[14] << " | " << cells[15] << std::endl;  
// }