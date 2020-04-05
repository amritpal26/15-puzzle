#include "include/PatternDatabase.h"

using database::PatternDatabase;

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

int
main(int argc, char* argv[]) {
    PatternDatabase PatternDatabase = {startingPatterns};

    return 0;
};