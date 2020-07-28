#include "dayofyear.hpp"

DayOfYear::DayOfYear(int day){
    m_day = day;
}

void DayOfYear::print(){

    int tmpDay = m_day;
    int monthIdx = 1;

    bool flip = false;

    while(tmpDay >= 30){
        if(monthIdx == 1){
            tmpDay -= 28;
        }else{
            tmpDay -= flip ? 31 : 30;
        }
        monthIdx++;
    }

    std::cout << STR_MONTHS[monthIdx] << " " << tmpDay;
}