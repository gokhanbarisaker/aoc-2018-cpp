#include "claim.hpp"

Claim::Claim(int id, Point &offset, Point &size) : id(id), offset(offset), size(size) {}

std::ostream &operator<<(std::ostream &os, Claim &claim)
{
    return os << "#" << claim.id << " @ " << claim.offset.x << "," << claim.offset.y << ": " << claim.size.x << "x" << claim.size.y;
}
