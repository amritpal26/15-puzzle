#pragma once

#include "Pattern.h"
#include <string>
#include <vector>
#include <unordered_map>

namespace database {

struct Database{
    std::unordered_map<std::string, int> patterns;
    std::vector<int> tiles;
};

class PatternDatabase {
private:
    void generatePatterns(Pattern startingPattern, Database& patternDB);

    std::vector<Pattern> getAllChildPatterns(const Pattern& pattern);

    std::vector<Database> patternDatabases;

public:

    PatternDatabase(std::vector<std::vector<int> > patterns);

    int getHeuristic(const Pattern& pattern) const;
};
}