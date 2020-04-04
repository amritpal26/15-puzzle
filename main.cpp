#include "include/PatternDatabase.h"

using database::PatternDatabase;

std::vector< std::vector<int> > startingPatterns= {
    {   1, 2, 3, 0,
        5, 6, 0, 0,
        0, 0, 0, 0, 
        0, 0, 0, 0
    },
    {
        0, 0, 0, 4,
        0, 0, 7, 8,
        0, 0, 11, 12,
        0, 0, 0, 0
    },
    {
        0, 0, 0, 0,
        0, 0, 0, 0,
        9, 10, 0, 0,
        13, 14, 15, 0
    }
};

int
main(int argc, char* argv[]) {
    PatternDatabase PatternDatabase = {startingPatterns};

    return 0;
};