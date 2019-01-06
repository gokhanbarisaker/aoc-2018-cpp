#include "timeentry.hpp"

TimeEntry::TimeEntry(date::sys_seconds time, int guardId, State &state) : time(time), guardId(guardId), state(state) {}

bool TimeEntry::operator==(const TimeEntry &timeEntry) const
{
    return time == timeEntry.time;
}

bool TimeEntry::operator!=(const TimeEntry &timeEntry) const
{
    return !operator==(timeEntry);
}

bool TimeEntry::operator<(const TimeEntry &timeEntry) const
{
    return time < timeEntry.time;
}

bool TimeEntry::operator>(const TimeEntry &timeEntry) const
{
    return timeEntry.operator<(*this);
}

bool TimeEntry::operator<=(const TimeEntry &timeEntry) const
{
    return !operator>(timeEntry);
}

bool TimeEntry::operator>=(const TimeEntry &timeEntry) const
{
    return !operator<(timeEntry);
}

std::ostream &operator<<(std::ostream &os, TimeEntry &timeEntry)
{
    os << "["
       << date::format("%Y-%m-%d %H:%M", timeEntry.time)
       << "] Guard #" << timeEntry.guardId;

    switch (timeEntry.state)
    {
    case State::START:
    {
        os << " begins shift";
        break;
    }
    case State::ASLEEP:
    {
        os << " falls asleep";
        break;
    }
    case State::AWAKE:
    {
        os << " wakes up";
        break;
    }
    }

    return os;
}