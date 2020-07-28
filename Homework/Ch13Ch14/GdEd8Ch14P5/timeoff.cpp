#include "timeoff.hpp"

TimeOff::TimeOff(std::string name, int id){
    SetName(name);
    SetId(id);
    maxVacation.SetHours(120);
}
void TimeOff::SetName(std::string name){
    m_name = name;
}
void TimeOff::SetId(int id){
    m_id = id;
}

void TimeOff::Set_MaxSickDays(int hours){
    maxSickDays.SetHours(hours);
}
void TimeOff::Set_SickTaken(int hours){
    sickTaken.SetHours(hours);

}
void TimeOff::Set_MaxVacation(int hours){
    maxVacation.SetHours(hours);

}
bool TimeOff::Set_VacTaken(int hours){
    if(vacTaken.GetHours() + hours < maxVacation.GetHours()){
        vacTaken += NumDays(hours);
        return true;
    }else{
        return false;
    }

}
void TimeOff::Set_MaxUnpaid(int hours){
    maxUnpaid.SetHours(hours);

}
void TimeOff::Set_UnpaidTaken(int hours){
    unpaidTaken.SetHours(hours);

}

std::string TimeOff::GetName(){
    return m_name;
} 
int TimeOff::GetId(){
    return m_id;
}

NumDays TimeOff::Set_MaxSickDays(){
    return maxSickDays;
}
NumDays TimeOff::Get_SickTaken(){
    return sickTaken;
}
NumDays TimeOff::Get_MaxVacation(){
    return maxSickDays;
}
NumDays TimeOff::Get_VacTaken(){
    return maxVacation;
}
NumDays TimeOff::Get_MaxUnpaid(){
    return vacTaken;
}
NumDays TimeOff::Get_UnpaidTaken(){
    return unpaidTaken;
}
~TimeOff(){

}