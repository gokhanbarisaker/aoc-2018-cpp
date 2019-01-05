#include <iostream>
#include <functional>

class Day2
{
  public:
    void solve();

  private:
    void solveFirstPart();
    void solveSecondPart();
    void parseStream(std::istream &, std::function<void(std::string &)>);
    int checksum(int, int);
    std::vector<std::string> findCommonIds(std::vector<std::string> &, int);
    bool equals(std::string &, std::string &, int);
};