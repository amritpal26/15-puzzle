#include "../include/PatternDatabase.h"

#include <queue>
#include <algorithm>
#include <iostream>
#include <string>

using database::PatternDatabase;
using database::Pattern;
using puzzle::Direction;

struct Node {
    Pattern pattern;
    int moves;
};

PatternDatabase::PatternDatabase(std::vector<std::vector<int> > patterns)
{
    std::cout << "creating first: " << std::endl;
    generatePatterns({patterns[0]}, patternDB1);
    std::cout << "creating second: " << std::endl;
    generatePatterns({patterns[1]}, patternDB2);
    std::cout << "creating third: " << std::endl;
    generatePatterns({patterns[2]}, patternDB3);
    std::cout << "finished" << std::endl;
}

void 
PatternDatabase::generatePatterns(Pattern startingPattern, std::unordered_map<std::string, Pattern>& patternDB)
{
    std::vector<int> tiles;
    std::vector<int> startingCells = startingPattern.getCells();
    std::copy_if(startingCells.begin(), startingCells.end(), std::back_inserter(tiles),
        [] (int cell) { return cell > 0; }
    );

    int size = 524160;
    patternDB.reserve(size);

    int moves = 0;    
    std::queue<Pattern> frontier;
    frontier.push(startingPattern);
    
    std::string startingId = Pattern::getId(tiles, startingPattern.getCells());
    patternDB.insert( {startingId, startingPattern} );
    
    while (!frontier.empty()){
        // moves++;
        Pattern currentPattern = frontier.front();
        frontier.pop();

        if (patternDB.size() % 1000 == 0)
            std::cout << patternDB.size() << ": " << frontier.size() << std::endl;        

        std::vector<Pattern> patterns = currentPattern.getAllReachablePatterns(tiles);
        for (Pattern& newPattern : patterns){
            std::string id = Pattern::getId(tiles, newPattern.getCells());
            auto itr = patternDB.find(id);
            newPattern.moves = moves;
            
            if (itr == patternDB.end()){
                patternDB.insert({id, newPattern});
                frontier.push(newPattern);
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