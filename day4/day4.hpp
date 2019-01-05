#include <iostream>
#include <functional>

class Day4
{
  public:
    void solve();

  private:
    void solveFirstPart();
    void solveSecondPart();
    void parseInput(std::istream &, std::function<void(bool &)>);
};