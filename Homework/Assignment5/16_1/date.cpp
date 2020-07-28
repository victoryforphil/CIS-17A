#include "Date.hpp"
Date::Date(/* args */)
{
    // Init vars to first valid date using UNIX time;
    m_year = 1970;
    m_day = 1;
    m_month = 1;
}

void Date::SetMonth(short month){
    if(month >= 1 && month <= 12){ // Input Validation
        m_month = month;
        
        //return true; // Return true if successfully set
    }else{
        throw InvalidMonth();
        //return false; // Return false if validation failed 
    }
}

void Date::SetDay(short day){
    if(day >= 1 && m_day <= 31){ // Input Validation
        m_day = day;
        //return true; // Return true if successfully set
    }else{
        throw InvalidDay();
        //return false; // Return false if validation failed 
    }
}

void Date::SetYear(short year){
    m_year = year;
    //return true; // Return true if successfully set
}

short Date::GetDay(){
    return m_day;
}

short Date::GetMonth(){
    return m_month;
}

short Date::GetYear(){
    return m_year;
}

Date::~Date()
{
}

