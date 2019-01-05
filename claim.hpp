#include "point.hpp"

#include <iostream>

class Claim
{
public:
  const int id;
  const Point offset;
  const Point size;
  Claim(int id, Point &, Point &);

  friend std::ostream &operator<<(std::ostream &, Claim &claim);
};