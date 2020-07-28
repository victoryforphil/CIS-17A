#ifndef _MILTIME_H_
#define _MILTIME_H_

#include "time.hpp"
#include <exception>

struct BadHour : public std::exception
{
	const char * what () const throw ()
    {
    	return "Please enter a mil-time time between 0 and 2359";
    }
};

struct BadSeconds : public std::exception
{
	const char * what () const throw ()
    {
    	return "Please enter a valid seconds between 0 and 59";
    }
};
class MilTime : public Time
{
private:
    int m_milHours;
    int m_milSecs;
public:
    MilTime();
    MilTime(int hours, int secs);
    void SetTime(int hours, int secs);
    int GetHour();
    int GetStandHr();
};





#endif