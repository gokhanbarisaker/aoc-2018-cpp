#include "day2.hpp"

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>

void Day2::solve()
{
    std::cout << "TODO" << std::endl;

    std::cout << "--- Day 2: Inventory Management System ---" << std::endl
              << "We have following challenges ahead..." << std::endl
              << "Part 1. What is the checksum for your list of box IDs?" << std::endl
              << "Part 2. What letters are common between the two correct box IDs?" << std::endl
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

void Day2::solveFirstPart()
{
    // TODO: Research UTF 8  string usage

    std::ifstream ifs{"day2\\day2.input"};
    int doubleCount{0};
    int tripleCount{0};

    parseStream(ifs, [&doubleCount, &tripleCount](std::string &boxId) {
        std::cout << "Box ID: " << boxId << std::endl;

        std::map<char, int> charCounts{};

        for (char &c : boxId)
        {
            charCounts[c]++;
        }

        std::set<int> uniqueCharCounts{};

        for (auto ukw : charCounts)
        {
            uniqueCharCounts.insert(ukw.second);
        }

        doubleCount += uniqueCharCounts.count(2);
        tripleCount += uniqueCharCounts.count(3);
    });

    std::cout << "Checksum: " << checksum(doubleCount, tripleCount) << std::endl;
}

void Day2::solveSecondPart()
{
    std::ifstream ifs{"day2\\day2.input"};
    std::vector<std::string> boxIds{};

    parseStream(ifs, [&boxIds](std::string &boxId) {
        boxIds.push_back(boxId);
    });

    auto commonBoxIds = findCommonIds(boxIds, 1);

    for (auto foo : commonBoxIds)
    {
        std::cout << "Found: " << foo << std::endl;
    }
}

void Day2::parseStream(std::istream &is, std::function<void(std::string &)> consumer)
{
    std::string boxId;

    while (is >> boxId)
    {
        consumer(boxId);
    }
}

int Day2::checksum(int a, int b)
{
    return a * b;
}

std::vector<std::string> Day2::findCommonIds(std::vector<std::string> &boxIds, int faultThreshold)
{
    std::vector<std::string> commonIds{};

    for (size_t i = 0; i < boxIds.size() - 1; ++i)
    {
        auto referenceBoxId = boxIds[i];

        for (size_t j = i + 1; j < boxIds.size(); j++)
        {
            auto boxId = boxIds[j];

            if (equals(referenceBoxId, boxId, faultThreshold))
            {
                commonIds.push_back(boxId);
                commonIds.push_back(referenceBoxId);
            }
        }
    }

    return commonIds;
}

bool Day2::equals(std::string &s1, std::string &s2, int faultThreshold)
{
    char c1;
    char c2;
    int faultCount{0};

    for (size_t i = 0; i < s1.size(); ++i)
    {
        c1 = s1[i];
        c2 = s2[i];

        if (c1 != c2)
        {
            ++faultCount;
        }
    }

    return faultCount <= faultThreshold;
}