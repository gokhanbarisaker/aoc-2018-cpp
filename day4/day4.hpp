#include <iostream>
#include <functional>

#include "../timeentry.hpp"

class Day4
{
public:
  void solve();

private:
  void solveFirstPart();
  void solveSecondPart();
  void parseInput(std::istream &, std::function<void(TimeEntry &)>);
  void affiliateGuardIds(std::vector<TimeEntry> &timeEntries);
  TimeEntry &findSleepiest(std::vector<TimeEntry> &timeEntries);
};