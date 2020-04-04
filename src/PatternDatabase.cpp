#include "../include/PatternDatabase.h"

#include <queue>
#include <algorithm>
#include <iostream>

using database::PatternDatabase;
using database::Pattern;
using puzzle::Direction;

struct Node {
    Pattern pattern;
    int moves;
};

PatternDatabase::PatternDatabase(std::vector<std::vector<int> > patterns)
    : startingPatterns(patterns)
{
    directions = {Direction::Up, Direction::Left, Direction::Right, Direction::Down};

    std::cout << "creating first: " << std::endl;
    generatePatterns(patterns[0], patternDB1);
    std::cout << "creating second: " << std::endl;
    generatePatterns(patterns[1], patternDB2);
    std::cout << "creating third: " << std::endl;
    generatePatterns(patterns[2], patternDB3);
    std::cout << "finished" << std::endl;
}

void 
PatternDatabase::generatePatterns(Pattern startingPattern, std::vector<Pattern>& patternDB)
{
    int moves = 0;
    int count = 0;
    
    std::queue<Node> frontier;
    frontier.push( {startingPattern, moves} );

    while (!frontier.empty()){
        Node currentNode = frontier.front();
        Pattern currentPattern = currentNode.pattern;
        frontier.pop();
        
        // std::cout << ++count <<std::endl;
        auto it = std::find_if(patternDB.begin(), patternDB.end(),
            [currentPattern] (const Pattern& pattern) { 
                return pattern.equals(currentPattern); }
        );

        if (it == patternDB.end()){
            for (int i = 0; i < currentPattern.getSize(); i++){
                for (auto direction : directions){
                    if (currentPattern.isValidPermutation(i, direction)){
                        Pattern permutation = currentPattern.createPermutation(i, direction);
                        Node node = {permutation, moves};
                        frontier.push(node);
                        patternDB1.emplace_back(permutation);
                    }
                }
            }   
        }
    }
}

int 
getHeuristic(const Pattern& pattern)
{
    //TODO: Implement this function.
    return 0;
}