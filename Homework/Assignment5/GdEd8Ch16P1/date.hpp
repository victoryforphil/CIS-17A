#ifndef _DATE_H
#define _DATE_H_
#include <exception>

struct InvalidDay : public std::exception
{
	const char * what () const throw ()
    {
    	return "Please enter a day betwen 1 and 31";
    }
};

struct InvalidMonth : public std::exception
{
	const char * what () const throw ()
    {
    	return "Please enter a month betwen 1 and 12";
    }
};

class Date
{
private:
    short m_month;
    short m_day;
    short m_year;
public:
    Date(/* args */);
    void SetMonth(short month);
    void SetDay(short day);
    void SetYear(short year);

    short GetMonth();
    short GetDay();
    short GetYear();
    ~Date();
};


#endif