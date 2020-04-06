#include "Pattern.h"
#include <string>
#include <vector>
#include <unordered_map>

namespace database {
class PatternDatabase {

private:

    void generatePatterns(Pattern startingPattern, std::unordered_map<std::string, Pattern>& patternDB);

    std::vector<Pattern> getAllChildPatterns(const Pattern& pattern);

    std::unordered_map<std::string, Pattern> patternDB1;

    std::unordered_map<std::string, Pattern> patternDB2;

    std::unordered_map<std::string, Pattern> patternDB3;

public:

    PatternDatabase(std::vector<std::vector<int> > patterns);

    int getHeuristic(const Pattern& pattern);
};
}