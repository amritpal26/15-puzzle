#include "../include/PatternDatabase.h"

#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_map>

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
    generatePatterns({patterns[0], 15}, patternDB1);
    std::cout << "creating second: " << std::endl;
    generatePatterns({patterns[1], 15}, patternDB2);
    std::cout << "creating third: " << std::endl;
    generatePatterns({patterns[2], 15}, patternDB3);
    std::cout << "finished" << std::endl;
}

void 
PatternDatabase::generatePatterns(Pattern startingPattern, std::vector<Pattern>& patternDB44)
{
    std::vector<int> tiles = {1,2,3,5,6};
    int moves = 0;
    std::unordered_map<std::string, Pattern> patternDB;
    
    std::queue<Node> frontier;
    frontier.push( {startingPattern, moves} );
    
    std::string startingId = Pattern::getId(tiles, startingPattern.getCells());
    patternDB.insert({startingId, startingPattern});

    patternDB.reserve(524160);
    while (!frontier.empty()){
        Node currentNode = frontier.front();
        Pattern currentPattern = currentNode.pattern;
        frontier.pop();

        if (patternDB.size() % 1000 == 0)
            std::cout << patternDB.size() << ": " << patternDB.bucket_count() << std::endl;        

        std::vector<Pattern> patterns = currentPattern.getAllReachablePatterns();
        for (Pattern& newPattern : patterns){
            std::string id = Pattern::getId(tiles, newPattern.getCells());
            auto itr = patternDB.find(id);
            
            if (itr == patternDB.end()){
                patternDB.insert({id, currentPattern});
                frontier.push({std::move(newPattern), 0});
            }    
        }
    }
    std::cout << "dsdks" << std::endl;
}

int 
getHeuristic(const Pattern& pattern)
{
    //TODO: Implement this function.
    return 0;
}