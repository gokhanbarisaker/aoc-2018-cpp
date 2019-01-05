#include "bot.hpp"
#include "day1/day1.hpp"
#include "day2/day2.hpp"
#include "day3/day3.hpp"
#include "day4/day4.hpp"

enum class Command
{
    DAY1,
    DAY2,
    DAY3,
    DAY4,
    QUIT,
    UNKNOWN
};

void Bot::run()
{
    Command c = Command::UNKNOWN;

    do
    {
        promptOptions();
        c = readCommand();
    } while (executeCommand(c));
}

void Bot::promptOptions(std::ostream &out)
{
    // TODO: Investiate navigatable cli menus, etc...
    out << "1. Day 1" << std::endl
        << "2. Day 2" << std::endl
        << "3. Day 3" << std::endl
        << "99. Quit" << std::endl;
}

Command Bot::readCommand(std::istream &in)
{
    int input;

    std::cin >> input;

    switch (input)
    {
    case 1:
    {
        return Command::DAY1;
    }
    case 2:
    {
        return Command::DAY2;
    }
    case 3:
    {
        return Command::DAY3;
    }
    case 4:
    {
        return Command::DAY4;
    }
    case 99:
    {
        return Command::QUIT;
    }
    }

    return Command::UNKNOWN;
}

bool Bot::executeCommand(Command &c, std::ostream &out)
{
    switch (c)
    {
    case Command::DAY1:
    {
        Day1{}.solve();
        return true;
    }
    case Command::DAY2:
    {
        Day2{}.solve();
        return true;
    }
    case Command::DAY3:
    {
        Day3{}.solve();
        return true;
    }
    case Command::DAY4:
    {
        Day4{}.solve();
        return true;
    }
    case Command::QUIT:
    {
        out << "Bye" << std::endl;
        return false;
    }
    case Command::UNKNOWN:
    {
        out << "Bip, bip, bop, bup!.. failure!..." << std::endl;
        return true;
    }
    default:
    {
        // TODO: Be more clear about what was the command argument.
        // TODO: If possible, offer steps to fix it.
        throw std::invalid_argument("Given command is not recognized");
    }
    }
}