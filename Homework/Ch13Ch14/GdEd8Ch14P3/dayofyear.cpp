#include "dayofyear.hpp"

DayOfYear::DayOfYear(std::string month, int day)
{

    m_day = day;

    if (month == "January")
    {
        m_day += 31;
    }
    if (month == "Febuaray")
    {
        m_day += 28;
    }
    if (month == "March")
    {
        m_day += 30;
    }
    if (month == "April")
    {
        m_day += 31;
    }
    if (month == "May")
    {
        m_day += 30;
    }
    if (month == "June")
    {
        m_day += 31;
    }
    if (month == "July")
    {
        m_day += 30;
    }
    if (month == "August")
    {
        m_day += 31;
    }
    if (month == "September")
    {
        m_day += 30;
    }
    if (month == "October")
    {
        m_day += 31;
    }
    if (month == "November")
    {
        m_day += 30;
    }
    if (month == "December")
    {
        m_day += 31;
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
DayOfYear DayOfYear::operator--(int)
{
    DayOfYear temp = *this;
    --*this;
    return temp;
}