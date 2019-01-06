#include "date/date.h"

enum class State
{
    START,
    AWAKE,
    ASLEEP
};

class TimeEntry
{
  public:
    TimeEntry(date::sys_seconds time, int guardId, State &state);
    date::sys_seconds time;
    int guardId;
    State state;

    // Comparison operators
    bool operator==(const TimeEntry &) const;
    bool operator!=(const TimeEntry &) const;
    bool operator<(const TimeEntry &) const;
    bool operator>(const TimeEntry &) const;
    bool operator<=(const TimeEntry &) const;
    bool operator>=(const TimeEntry &) const;

    friend std::ostream &operator<<(std::ostream &, TimeEntry &);
};

constexpr int GUARDID_UNKNOWN = -1;
