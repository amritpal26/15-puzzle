#include "../include/PatternDatabase.h"

#include <queue>
#include <algorithm>
#include <iostream>
#include <string>

using database::PatternDatabase;
using database::Pattern;
using database::Direction;

PatternDatabase::PatternDatabase(std::vector<std::vector<int> > patterns)
{   
    Database db1;   Database db2;   Database db3;
    patternDatabases.push_back(db1);
    patternDatabases.push_back(db2);
    patternDatabases.push_back(db3);
    std::cout << "creating database for first pattern." << std::endl;
    generatePatterns({patterns[0]}, patternDatabases[0]);
    std::cout << "creating database for second pattern." << std::endl;
    generatePatterns({patterns[1]}, patternDatabases[1]);
    std::cout << "creating databse for third patter." << std::endl;
    generatePatterns({patterns[2]}, patternDatabases[2]);
    std::cout << "finished creating database." << std::endl;
}

void 
PatternDatabase::generatePatterns(Pattern startingPattern, Database& database)
{
    std::vector<int> startingCells = startingPattern.getCells();
    database.tiles.clear();
    std::copy_if(startingCells.begin(), startingCells.end(), std::back_inserter(database.tiles),
        [] (int cell) { return cell > 0; }
    );

    std::sort(database.tiles.begin(), database.tiles.end());

    int size = 524160;
    database.patterns.reserve(size);

    int moves = 0;    
    std::queue<Pattern> frontier;
    frontier.push(startingPattern);
    
    std::string startingId = Pattern::getId(database.tiles, startingPattern.getCells());
    database.patterns.insert( {startingId, startingPattern} );
    
    while (!frontier.empty()){
        moves++;
        Pattern currentPattern = frontier.front();
        frontier.pop();

        if (database.patterns.size() % 1000 == 0)
            std::cout << database.patterns.size() << ": " << frontier.size() << std::endl;        

        std::vector<Pattern> patterns = currentPattern.getAllReachablePatterns(database.tiles);
        for (Pattern& newPattern : patterns){
            std::string id = Pattern::getId(database.tiles, newPattern.getCells());
            auto itr = database.patterns.find(id);
            newPattern.moves = moves;
            
            if (itr == database.patterns.end()){
                database.patterns.insert({id, newPattern});
                frontier.push(newPattern);
            }
        }
    }
}

int 
PatternDatabase::getHeuristic(const Pattern& pattern) const
{
    int totalMoves = 0;
    for (auto db : patternDatabases){
        std::string id = Pattern::getId(db.tiles, pattern.getCells());
        totalMoves += db.patterns[id].moves;
    }
    return totalMoves;
}