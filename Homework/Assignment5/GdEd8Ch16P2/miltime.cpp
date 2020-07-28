#include "miltime.hpp"

/*

900 = 9 AM

1350 = 1:50 PM

1350 / 100 = 13 

12
*/

MilTime::MilTime(int hours, int secs){
    SetTime(hours, sec);
}

void MilTime::SetTime(int hours, int secs){

    if(hours > 2359 || hours < 0){
        //return false;
        throw BadHour();
    }
    if(secs > 59 || secs < 0){
        throw BadSeconds();
    }
    m_milHours = hours;
    m_milSecs = secs;

    hour = m_milHours / 100;
    if(hour > 12){
        hour -= 12;
    }
    min = m_milHours % 100;
    sec = m_milSecs;
    //return true;
}

int MilTime::GetHour(){
    return m_milHours;
}

int MilTime::GetStandHr(){
    return hour;
}