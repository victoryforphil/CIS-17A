#ifndef _DAY_OF_YEAR_H_
#define _DAY_OF_YEAR_H_

#include <string>
class DayOfYear
{
private:
    int m_day;
    static std::string STR_MONTHS[12] = {
        "January", "Febuaray", "March", "April",
        "May", "June", "July", "August", "September",
        "October", "November", "December"
    }


public:
    DayOfYear(int day);
    void print();
    ~DayOfYear();
};



#endif