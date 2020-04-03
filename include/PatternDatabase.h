#include "Pattern.h"
#include "Board.h"

using puzzle::Board;

class PatternDatabase {

private:

    void generatePatterns();

    std::vector<int> pattern1;

    std::vector<int> pattern2;

    std::vector<int> pattern3;
    
public:

    PatternDatabase(std::vector<std::vector<int> > startingPatterns);

    int getHeuristic(const Board& board);
};