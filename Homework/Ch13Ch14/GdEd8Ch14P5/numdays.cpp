#include "numdays.hpp"

NumDays::NumDays(int hours)
{
    SetHours(hours);
}

double NumDays::GetDays()
{
    return GetHours() / 8;
}
int NumDays::GetHours()
{
    return m_hours;
}
void NumDays::SetHours(int hours)
{
    hours = hours;
}

NumDays &NumDays::operator++()
{
    m_hours ++;
    return *this;
}

// Define postfix increment operator.
NumDays NumDays::operator++(int)
{
    NumDays temp = *this;
    ++*this;
    return temp;
}

// Define prefix decrement operator.
NumDays &NumDays::operator--()
{
    m_hours--;
    return *this;
}
NumDays NumDays::operator--(int)
{
   NumDays temp = *this;
   --*this;
   return temp;
}


NumDays NumDays::operator+(NumDays const &obj)
{   
    NumDays res (obj.m_hours + GetHours());
  
    return res;
}
NumDays NumDays::operator-(NumDays const &obj)
{
    NumDays res (obj.m_hours + GetHours());
    return res;
}
NumDays::~NumDays()
{
}
