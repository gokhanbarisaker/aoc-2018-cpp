#include "day3.hpp"

#include <fstream>
#include <map>

void Day3::solve()
{
    // solveFirstPart();

    solveSecondPart();
}

void Day3::solveFirstPart()
{
    std::cout << "TODO" << std::endl;

    std::ifstream ifs{"day3\\day3.input"};

    std::map<Point, int> pointClaimQuantities;

    parseInput(ifs, [&pointClaimQuantities](Claim &claim) {
        std::cout << claim << std::endl;

        for (int x = 0; x < claim.size.x; ++x)
        {
            for (int y = 0; y < claim.size.y; ++y)
            {
                Point p = claim.offset + Point{x, y};
                pointClaimQuantities[p]++;
            }
        }
    });

    int multipleClaimQuantity{0};

    for (auto const &[key, val] : pointClaimQuantities)
    {
        if (val > 1)
        {
            ++multipleClaimQuantity;
        }
    }

    std::cout << "Count: " << multipleClaimQuantity << std::endl;
}

void Day3::solveSecondPart()
{
    std::cout << "TODO" << std::endl;

    std::ifstream ifs{"day3\\day3.input"};

    std::map<Point, int> pointClaimQuantities;
    std::vector<Claim> claims;

    parseInput(ifs, [&pointClaimQuantities, &claims](Claim &claim) {
        std::cout << claim << std::endl;

        claims.push_back(claim);

        for (int x = 0; x < claim.size.x; ++x)
        {
            for (int y = 0; y < claim.size.y; ++y)
            {
                Point p = claim.offset + Point{x, y};
                pointClaimQuantities[p]++;
            }
        }
    });

    std::function<bool(Claim &)> predicate = [&pointClaimQuantities](Claim &claim) {
        for (int x = 0; x < claim.size.x; ++x)
        {
            for (int y = 0; y < claim.size.y; ++y)
            {
                Point p = claim.offset + Point{x, y};
                if (pointClaimQuantities[p] > 1)
                {
                    return false;
                }
            }
        }

        return true;
    };

    int index = findFirst(claims, predicate);

    std::cout << "Here you go ... ID# " << claims[index].id << std::endl;
}

void Day3::parseInput(std::istream &is, std::function<void(Claim &)> consumer)
{
    int id{0};
    int x{0};
    int y{0};
    int width{0};
    int height{0};

    std::string line;

    while (std::getline(is, line))
    {
        sscanf(line.c_str(), "#%d @ %d,%d: %dx%d", &id, &x, &y, &width, &height);

        Point offset{x, y};
        Point size{width, height};
        Claim c{id, offset, size};

        consumer(c);
    }
}

/**
 * Returns the index of the first element that matches the given predicate
 */
int Day3::findFirst(std::vector<Claim> &claims, std::function<bool(Claim &)> &predicate)
{
    int size = claims.size();

    for (int i = 0; i < size; i++)
    {
        Claim &claim = claims[i];

        if (predicate(claim))
        {
            return i;
        }
    }

    return -1;
}
