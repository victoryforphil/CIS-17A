#include "dayofyear.hpp"

DayOfYear::DayOfYear(std::string month, int day)
{

    m_day = day;
    switch (month)
    {
    case "January":
        m_day += 31;
        break;
    case "Febuaray":
        m_day += 28;
        break;
    case "March":
        m_day += 30;
        break;
    case "April":
        m_day += 31;
        break;
    case "May":
        m_day += 30;
        break;
    case "June":
        m_day += 31;
        break;
    case "July":
        m_day += 30;
        break;
    case "August":
        m_day += 31;
        break;
    case "September":
        m_day += 30;
        break;
    case "October":
        m_day += 31;
        break;
    case "November":
        m_day += 30;
        break;
    case "December":
        m_day += 31;
        break;
    }
}

void DayOfYear::print()
{

    int tmpDay = m_day;
    int monthIdx = 1;

    bool flip = false;

    while (tmpDay >= 30)
    {
        if (monthIdx == 1)
        {
            tmpDay -= 28;
        }
        else
        {
            tmpDay -= flip ? 31 : 30;
        }
        monthIdx++;
    }

    std::cout << STR_MONTHS[monthIdx] << " " << tmpDay;
}

// Define prefix increment operator.
DayOfYear &DayOfYear::operator++()
{
    m_day++;
    if (m_day > 365)
    {
        m_day = 1;
    }
    return *this;
}

// Define postfix increment operator.
DayOfYear DayOfYear::operator++(int)
{
    DayOfYear temp = *this;
    ++*this;
    return temp;
}

// Define prefix decrement operator.
DayOfYear &DayOfYear::operator--()
{
    m_day--;
    if (m_day < 1)
    {
        m_day = 365;
    }
    return *this;
}

// Define postfix decrement operator.
DayOfYear Point::operator--(int)
{
    DayOfYear temp = *this;
    --*this;
    return temp;
}