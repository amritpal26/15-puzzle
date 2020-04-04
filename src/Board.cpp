#include "../include/Board.h"
#include "math.h"

#include <iostream>
#include <algorithm>

using puzzle::Board;
using puzzle::Direction;

Board::Board() : 
    tiles({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, -1}),
    size(4)
{
}

void
Board::createNewBoard(){

}

std::vector<Direction> 
Board::getMoves(){
    std::vector<Direction> directions;
    if (position > 3){
        Direction direction = Up;
        directions.push_back(direction);
    } 
    if (position < 12){
        Direction direction = Up;
        directions.push_back(direction);
    } 
    if (position != 0 && position != 4 && position != 8 && position != 12){
        Direction direction = Up;
        directions.push_back(direction);
    } 
    if (position != 3 && position != 7 && position != 11 && position != 15){
        Direction direction = Up;
        directions.push_back(direction);
    }
    
    return directions;
}

void 
Board::makeMove(Direction direction){
    if (isValidMove(direction)){
        if(direction == Right){
            tiles[position] = tiles[position + 1];
            tiles[position + 1] = -1;
        }
        else if(direction == Left){
            tiles[position] = tiles[position - 1];
            tiles[position - 1] = -1;
        }
        else if(direction == Up){
            tiles[position] = tiles[position -  4];
            tiles[position - 4] = -1;
        }
        else if (direction == Down){
            tiles[position] = tiles[position + 4];
            tiles[position + 4] = -1;
        }
    } else{
        std::cerr << "invalid move" << std::endl;
    }
}

bool 
Board::isValidMove(Direction direction){
    if(direction == Direction::Right)
        return ((position+1) % 4) == 0;
    else if(direction == Direction::Left)
        return ((position-1) % 4) == 0;
    else if(direction == Direction::Up)
        return position > 3;
    else
        return position < 12;
}

void
Board::print(){
    std::cout << tiles[0] << " | " << tiles[1] << " | " << tiles[2] << " | " << tiles[3] << std::endl;  
    std::cout << tiles[4] << " | " << tiles[5] << " | " << tiles[6] << " | " << tiles[7] << std::endl;  
    std::cout << tiles[8] << " | " << tiles[9] << " | " << tiles[10] << " | " << tiles[11] << std::endl;  
    std::cout << tiles[12] << " | " << tiles[13] << " | " << tiles[14] << " | " << tiles[15] << std::endl;  
}