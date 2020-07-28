#ifndef _MILTIME_H_
#define _MILTIME_H_

#include "time.hpp"
class MilTime : public Time
{
private:
    int m_milHours;
    int m_milSecs;
public:
    MilTime();
    MilTime(int hours, int secs);
    bool SetTime(int hours, int secs);
    int GetHour();
    int GetStandHr();
};





#endif