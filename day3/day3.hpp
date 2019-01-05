#include <iostream>
#include <functional>

#include "../claim.hpp"

class Day3
{
public:
  void solve();

private:
  void solveFirstPart();
  void solveSecondPart();
  void parseInput(std::istream &, std::function<void(Claim &)>);
  int findFirst(std::vector<Claim> &frequencyChanges, std::function<bool(Claim &)> &predicate);
};