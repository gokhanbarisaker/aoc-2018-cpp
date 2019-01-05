#include "day4.hpp"

#include <fstream>
#include <string>
#include <regex>
#include "date/date.h"

void Day4::solve()
{
    solveFirstPart();
}

void Day4::solveFirstPart()
{
    // DONE: Iterate file stream
    // TODO: Parse into groups via regex
    // TODO: Parse date time format
    // TODO: Parse into time entry
    // TODO: Solve the problem

    std::ifstream ifs{"day4\\day4.input"};

    parseInput(ifs, [](bool &) {

    });
}

void Day4::solveSecondPart()
{
}

void Day4::parseInput(std::istream &is, std::function<void(bool &)> consumer)
{
    // Match 0: full text
    // Match 1: DateTime string
    // Match 2: Guard match
    // Match 3: Guard ID
    // Match 4: Sleep
    // Match 5: Wake up
    const std::string pattern = R"(\[(.+){1}\] (Guard #(\d+){1} begins shift)?(falls asleep)?(wakes up)?)";

    std::string line;
    std::regex regex(pattern);
    std::smatch match;

    while (std::getline(is, line))
    {
        if (std::regex_match(line, match, regex))
        {
            std::cout << "Match: " << match[5] << std::endl;
        }
    }
}