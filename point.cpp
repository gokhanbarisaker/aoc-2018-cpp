#include "point.hpp"
#include <math.h>

Point::Point(int x, int y) : x(x), y(y) {}

bool Point::operator==(const Point &point) const
{
    return x == point.x && y == point.y;
}

bool Point::operator!=(const Point &point) const
{
    return !operator==(point);
}

bool Point::operator<(const Point &point) const
{
    if (x == point.x)
    {
        return y < point.y;
    }

    return x < point.x;
}

bool Point::operator>(const Point &point) const
{
    return point.operator<(*this);
}

bool Point::operator<=(const Point &point) const
{
    return operator>(point);
}

bool Point::operator>=(const Point &point) const
{
    return operator<(point);
}

Point &Point::operator+=(const Point &point)
{
    x += point.x;
    y += point.y;

    return *this;
}

// inline Point operator+(Point left, const Point &right)
// {
//     left += right;
//     return left;
// }
