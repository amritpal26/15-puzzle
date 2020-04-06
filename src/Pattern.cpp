#include "../include/Pattern.h"
#include <iostream>
#include <sstream>

using database::Pattern;

Pattern::Pattern(){}

Pattern::Pattern(std::vector<int> _cells) : cells(_cells)    
{
}

bool
Pattern::equals(const Pattern& other) const {
    return std::equal(cells.begin(), cells.end(), other.cells.begin());
}

std::vector<int>
Pattern::getCells() const {
    return cells;
}

bool 
Pattern::isValidPermutation(int cellIndex, Direction direction){
    if(direction == Direction::Right && ((cellIndex+1) % 4) != 0 && cells[(cellIndex+1) % 4] <= 0)
        return true;
    else if(direction == Direction::Left && (cellIndex % 4) != 0 && cells[cellIndex % 4] <= 0)
        return true;
    else if(direction == Direction::Up && cellIndex > 3 && cells[cellIndex-4] <= 0)
        return true;
    else if (direction == Direction::Down && cellIndex < 12 && cells[cellIndex+4] <= 0)
        return true;
    
    return false;
}

Pattern
Pattern::createPermutation(int cellIndex, Direction direction){
    std::vector<int> permutationCells(cells.size());
    std::copy(cells.begin(), cells.end(), permutationCells.begin());

    //make move to permutation.
    int newCellIndex = cellIndex + getDelta(direction);
    int temp = permutationCells[newCellIndex];
    permutationCells[newCellIndex] = permutationCells[cellIndex];
    permutationCells[cellIndex] = temp;

    // Create and return the new pattern permutation.
    return {permutationCells};
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
Pattern::getAllReachablePatterns(const std::vector<int>& tiles) {
    std::vector<Pattern> reachablePatterns;
    for (auto tile : tiles){

        auto itr = find(cells.begin(), cells.end(), tile);
        int index = std::distance(cells.begin(), itr);

        for (int i = 0; i < 4; i++){
            Direction direction = static_cast<Direction>(i);
            if (isValidPermutation(index, direction)){
                Pattern pattern = createPermutation(index, direction);
                reachablePatterns.push_back(std::move(pattern));
            }
        }
    }
    return reachablePatterns;
}

std::string
Pattern::getId(const std::vector<int>& tiles, const std::vector<int>& cells){
    std::stringstream ss;
    std::string id = "";
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