#ifndef _TIME_OFF_H_
#define _TIME_OFF_H_

#include "numdays.hpp"
#include <string>

class TimeOff
{
private:
    NumDays maxSickDays;
    NumDays sickTaken;
    NumDays maxVacation;
    NumDays vacTaken;
    NumDays maxUnpaid;
    NumDays unpaidTaken;



    std::string m_name;
    int m_id;

public:
    TimeOff(std::string name, int id);
    void SetName(std::string name);
    void SetId(int id);
    


    void Set_MaxSickDays(int hours);
    void Set_SickTaken(int hours);
    void Set_MaxVacation(int hours);
    bool Set_VacTaken(int hours);
    void Set_MaxUnpaid(int hours);
    void Set_UnpaidTaken(int hours);

    std::string GetName()
    int GetId();

    NumDays Set_MaxSickDays();
    NumDays Get_SickTaken();
    NumDays Get_MaxVacation();
    NumDays Get_VacTaken();
    NumDays Get_MaxUnpaid();
    NumDays Get_UnpaidTaken();
    ~TimeOff();
};

#endif