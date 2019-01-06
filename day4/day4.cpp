#include "day4.hpp"

#include <fstream>
#include <string>
#include <regex>

void Day4::solve()
{
    solveFirstPart();
}

void Day4::solveFirstPart()
{
    // DONE: Iterate file stream
    // DONE: Parse into groups via regex
    // DONE: Parse date time format
    // DONE: Parse into time entry
    // TODO: Solve the problem

    std::ifstream ifs{"day4\\day4.input"};
    std::vector<TimeEntry> timeEntries{};

    parseInput(ifs, [&timeEntries](TimeEntry &timeEntry) {
        //std::cout << timeEntry << std::endl;
        timeEntries.push_back(timeEntry);
    });

    std::sort(timeEntries.begin(), timeEntries.end());

    affiliateGuardIds(timeEntries);

    // for (auto timeEntry : timeEntries)
    // {
    //     std::cout << timeEntry << std::endl;
    // }

    TimeEntry &timeEntry = findSleepiest(timeEntries);

    auto date = date::floor<date::days>(timeEntry.time);
    int minute = date::make_time(timeEntry.time - date).minutes;

    std::cout << "Guard ID x Minute = " << (timeEntry.guardId * minute) << std::endl;
}

void Day4::solveSecondPart()
{
}

date::sys_seconds parse(const std::string &);

void Day4::parseInput(std::istream &is, std::function<void(TimeEntry &)> consumer)
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
    date::sys_seconds tp;
    int guardId = GUARDID_UNKNOWN;
    State state;

    while (std::getline(is, line))
    {
        if (std::regex_match(line, match, regex))
        {
            std::istringstream(match[1]) >>
                date::parse("%Y-%m-%d %H:%M", tp);

            guardId = match[3].matched ? std::stoi(match[3]) : GUARDID_UNKNOWN;

            if (match[2].matched)
            {
                state = State::START;
            }
            else if (match[4].matched)
            {
                state = State::ASLEEP;
            }
            else if (match[5].matched)
            {
                state = State::AWAKE;
            }

            TimeEntry timeEntry{tp, guardId, state};

            consumer(timeEntry);
        }
    }
}

void Day4::affiliateGuardIds(std::vector<TimeEntry> &timeEntries)
{
    int guardId = GUARDID_UNKNOWN;

    for (auto &timeEntry : timeEntries)
    {
        if (timeEntry.guardId == GUARDID_UNKNOWN)
        {
            timeEntry.guardId = guardId;
        }
        else
        {
            guardId = timeEntry.guardId;
        }

        std::cout << guardId;
    }
}

TimeEntry &Day4::findSleepiest(std::vector<TimeEntry> &timeEntries)
{
    TimeEntry &sleepiestTimeEntry = timeEntries[0];
    date::sys_seconds sleepiestDuration;
    date::sys_seconds sleepStart;

    for (const auto &timeEntry : timeEntries)
    {
        switch (timeEntry.state)
        {
        case State::ASLEEP:
        {
            sleepStart = timeEntry.time;
            break;
        }
        default:
        {

            break;
        }
        }
    }

    return sleepiestTimeEntry;
}