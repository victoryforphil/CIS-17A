#ifndef _DATE_H
#define _DATE_H_

class Date
{
private:
    short m_month;
    short m_day;
    short m_year;
public:
    Date(/* args */);
    bool SetMonth(short month);
    bool SetDay(short day);
    bool SetYear(short year);

    short GetMonth();
    short GetDay();
    short GetYear();
    ~Date();
};


#endif