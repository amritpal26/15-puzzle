#include "../include/Pattern.h"
#include <iostream>
#include <sstream>

using database::Pattern;


Pattern::Pattern(std::vector<int> _cells, int _zeroCellPosition) :
        cells(_cells),
        zeroCellPosition(_zeroCellPosition),
    
        directions({Direction::Up, Direction::Left, Direction::Right, Direction::Down})
{
}

bool
Pattern::equals(const Pattern& other) const {
    return std::equal(cells.begin(), cells.end(), other.cells.begin());
}

bool 
Pattern::isValidPermutation(Direction direction){
    if(direction == Direction::Right && ((zeroCellPosition+1) % 4) != 0)
        return true;
    else if(direction == Direction::Left && (zeroCellPosition % 4) != 0)
        return true;
    else if(direction == Direction::Up && zeroCellPosition > 3)
        return true;
    else if (direction == Direction::Down && zeroCellPosition < 12)
        return true;
    
    return false;
}

Pattern
Pattern::createPermutation(Direction direction){
    std::vector<int> permutationCells(cells.size());
    std::copy(cells.begin(), cells.end(), permutationCells.begin());

    //make move to permutation.
    int newCellIndex = zeroCellPosition + getDelta(direction);
    int temp = permutationCells[newCellIndex];
    permutationCells[newCellIndex] = permutationCells[zeroCellPosition];
    permutationCells[zeroCellPosition] = temp;

    // Create and return the new pattern permutation.
    Pattern pattern = {permutationCells, newCellIndex};
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

std::vector<Pattern>
Pattern::getAllReachablePatterns() {
    std::vector<Pattern> reachablePatterns;
    for (auto direction : directions){
        if (isValidPermutation(direction)){
            Pattern pattern = createPermutation(direction);
            reachablePatterns.emplace_back(std::move(pattern));
        }
    }
    return reachablePatterns;
}

std::vector<int>
Pattern::getCells() const {
    return cells;
}

std::string
Pattern::getId(std::vector<int> tiles, std::vector<int> cells){
    std::stringstream ss;
    std::string id = "";
    // tiles.push_back(0);
    for (auto tile : tiles){
        auto itr = find(cells.begin(), cells.end(), tile);
        int index = std::distance(cells.begin(), itr);
        if (index == 0)
            ss << "00";
        else if (index < 10)
            ss << "0" << index;
        else
            ss << index;
    }
    return ss.str();
}