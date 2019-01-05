class Point
{
public:
  int x, y;
  Point(int = 0, int = 0);
  constexpr Point operator+(const Point &);

  // Comparison operators
  bool operator==(const Point &) const;
  bool operator!=(const Point &) const;
  bool operator<(const Point &) const;
  bool operator>(const Point &) const;
  bool operator<=(const Point &) const;
  bool operator>=(const Point &) const;

  // Binary aritmetic operators
  Point &operator+=(const Point &point);
};

inline Point operator+(Point left, const Point &right)
{
  left += right;
  return left;
}
