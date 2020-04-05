#include "Pattern.h"

#include <vector>

namespace database {
class PatternDatabase {

private:

    void generatePatterns(Pattern startingPattern, std::vector<Pattern>& patternDB);

    std::vector<Pattern> getAllChildPatterns(const Pattern& pattern);

    std::vector<Pattern> patternDB1;

    std::vector<Pattern> patternDB2;

    std::vector<Pattern> patternDB3;

public:

    PatternDatabase(std::vector<std::vector<int> > patterns);

    int getHeuristic(const Pattern& pattern);
};
}