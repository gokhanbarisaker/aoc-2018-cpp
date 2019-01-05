#include <iostream>

enum class Command;

class Bot
{
public:
  void run();

private:
  void promptOptions(std::ostream &out = std::cout);
  Command readCommand(std::istream &in = std::cin);
  bool executeCommand(Command &c, std::ostream &out = std::cout);
};