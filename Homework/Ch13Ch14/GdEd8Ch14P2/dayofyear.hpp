#ifndef _DAY_OF_YEAR_H_
#define _DAY_OF_YEAR_H_

#include <iostream>
#include <string>
class DayOfYear
{
private:
    int m_day;
    inline const static std::string STR_MONTHS[12] = {
        "January", "Febuaray", "March", "April",
        "May", "June", "July", "August", "September",
        "October", "November", "December"
    };


public:
    DayOfYear(int day);
    void print();
    DayOfYear& operator++();       // Prefix increment operator.
    DayOfYear operator++(int);     // Postfix increment operator.

    // Declare prefix and postfix decrement operators.
    DayOfYear& operator--();       // Prefix decrement operator.
    DayOfYear operator--(int);     // Postfix decrement operator.
    //~DayOfYear();
};



#endif