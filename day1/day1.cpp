#include "day1.hpp"

#include <fstream>
#include <algorithm>
#include <set>

void Day1::solve()
{
    std::cout << "--- Day 1: Chronal Calibration ---" << std::endl
              << "We have following challenges ahead..." << std::endl
              << "Part 1. Starting with a frequency of zero, what is the resulting frequency after all of the changes in frequency have been applied?" << std::endl
              << "Part 2. What is the first frequency your device reaches twice?" << std::endl
              << "Which one would you like to solve? (1 or 2): ";

    int input;

    std::cin >> input;

    switch (input)
    {
    case 1:
        solveFirstPart();
        break;

    case 2:
    {
        solveSecondPart();
        break;
    }
    default:
        std::cout << "¯\\_(ツ)_/" << std::endl;
        break;
    }
}

void Day1::solveFirstPart()
{
    // TODO: Apply functional stuff...
    std::ifstream ifs{"day1\\day1.input"};
    int frequency{0};

    parseStream(ifs, [&frequency](int &frequencyChange) {
        std::cout << "Current frequency " << frequency << ", change of " << frequencyChange;
        frequency += frequencyChange;
        std::cout << "; resulting frequency " << frequency << "." << std::endl;
    });

    std::cout << "Final frequency: " << frequency << std::endl;
}

void Day1::solveSecondPart()
{
    int frequency{0};
    std::ifstream ifs{"day1\\day1.input"};
    std::vector<int> frequencyChanges{};
    std::vector<int> frequencyHistory{frequency};

    parseStream(ifs, [&frequencyChanges](int &frequencyChange) {
        frequencyChanges.push_back(frequencyChange);
    });

    // TODO: Try with copy value & lambda combo
    std::function<bool(int &)> predicate = [&frequencyHistory, &frequency](int &frequencyChange) {
        frequency += frequencyChange;
        bool found = std::find(frequencyHistory.begin(), frequencyHistory.end(), frequency) != frequencyHistory.end();
        frequencyHistory.push_back(frequency);

        std::cout << "Change: " << frequencyChange << "\t, Frequency: " << frequency << "\t, H.Size: " << frequencyHistory.size() << std::endl;

        return found;
    };

    int index;

    while ((index = findFirst(frequencyChanges, predicate)) == -1)
    {
        std::cout << "Looping again..." << std::endl;
    };

    if (index == -1)
    {
        std::cout << "Not found :(" << std::endl;
    }
    else
    {
        std::cout << "Found: " << frequencyHistory.back() << std::endl;
    }
}

void Day1::parseStream(std::istream &is, std::function<void(int &)> consumer)
{
    int frequencyChange;

    while (is >> frequencyChange)
    {
        consumer(frequencyChange);
    }
}

/**
 * Returns the index of the first element that matches the given predicate
 */
int Day1::findFirst(std::vector<int> &frequencyChanges, std::function<bool(int &)> &predicate)
{
    int frequencyChange;
    int size = frequencyChanges.size();

    for (int i = 0; i < size; i++)
    {
        frequencyChange = frequencyChanges[i];

        if (predicate(frequencyChange))
        {
            return i;
        }
    }

    return -1;
}
