#include <iostream>
#include <vector>
#include <functional>

class Day1
{
public:
  void solve();

private:
  void solveFirstPart();
  void solveSecondPart();
  void parseStream(std::istream &, std::function<void(int &)>);
  int findFirst(std::vector<int> &, std::function<bool(int &)> &);
};