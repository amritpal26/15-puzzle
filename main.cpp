#include "include/PatternDatabase.h"
#include "include/Board.h"
#include "include/Search.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using database::PatternDatabase;
using puzzle::Board;

std::vector< std::vector<int> > startingPatterns= {
    {   1, 2, 3, -1,
        5, 6, -1, -1,
        -1, -1, -1, -1, 
        -1, -1, -1, 0
    },
    {
        -1, -1, -1, 4,
        -1, -1, 7, 8,
        -1, -1, 11, 12,
        -1, -1, -1, 0
    },
    {
        -1, -1, -1, -1,
        -1, -1, -1, -1,
        9, 10, -1, -1,
        13, 14, 15, 0
    }
};

void showHelp();

std::vector<int> getBoard(std::string input);

int
main(int argc, char* argv[]) {
    PatternDatabase patternDatabase = {startingPatterns};

    showHelp();

    while (1){
        std::string input;
        getline(std::cin, input);
        
        if (input == "q" || input == "Q" || input == "Quit" )
            return 0;

        std::vector<int> boardState = getBoard(input);
        if (boardState.size() == 0){
            std::cout << "incorrect input" << std::endl;
            showHelp();
            continue;
        }

        Board board = {boardState, patternDatabase};

        puzzle::Search search;

        search.solve(board);






        std::cout << "\nEnter a new board or quit." << std::endl;
    }

    return 0;
};

void 
showHelp(){
    std::string prompt = "To quit the game press 'q'\n"
        "To solve a new board enter the board as shown in the example below\n"
        "example: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 0\n";
    
    std::cout << prompt;
}

bool
isValidBoardState(std::vector<int> nums){

    if (nums.size() != 16)
        return false;
    
    sort(nums.begin(), nums.end());

    for (int i = 0; i < 16; i++){
        if (nums[i] != i)
            return false;
    }
    
    return true;
}

std::vector<int> 
getBoard(std::string input){

    std::vector<int> nums;
	std::istringstream iss(input);
	
    for(int s; iss >> s; )
        nums.push_back(s);
    
    if (!isValidBoardState(nums))
        nums.clear();

    return nums;
}