/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.cpp
 * Author: Victo
 * 
 * Created on July 28, 2020, 9:21 PM
 */

#include "Employee.hpp"

Employee::Employee(char name[20], char title[20], float rate)
{
    strcpy(MyName, name);
    // JobTitle = title;
    strcpy(JobTitle, title);
    HourlyRate = rate;
    HoursWorked = 0;
    GrossPay = 0.0;
    NetPay = 0.0;
}

double Employee::Tax(float amount)
{
    float rate = 0.1;
    if (amount < 1000 && amount > 500)
    {
        rate = 0.2;
    }
    else if (amount > 1000)
    {
        rate = 0.3;
    }

    return amount * rate;
}

float Employee::CalculatePay(float x, int y)
{
    return getNetPay(getGrossPay(setHourlyRate(x), setHoursWorked(y)));
}

float Employee::getGrossPay(float rate, int worked)
{
    float amount = getNetPay(worked);
    amount -= Tax(amount);
    GrossPay = amount;
    return amount;
}

float Employee::getNetPay(float hours)
{

    float cntHrs = hours;
    float wrtHrs = 0;

    while (cntHrs != 0)
    {
        if (hours > 50)
        {
            wrtHrs += 2;
        }
        else if (hours > 40 && hours < 50)
        {
            wrtHrs += 1.5;
        }
        else
        {
            wrtHrs += 1;
        }
        cntHrs--;
    }
    NetPay = hours * HourlyRate;
    return NetPay;
}

std::string Employee::toString()
{
    std::string out = "Worker Information: ";
    out += "\n\t- Name: ";
    out += MyName;
    out += "\n\t- Title: ";
    out += JobTitle;
    out += "\n\t- HourlyRate: ";
    out += std::to_string(HourlyRate);
    out += "\n\t- HoursWorked: ";
    out += std::to_string(HoursWorked);
    out += "\n\t- GrossPay: ";
    out += std::to_string(GrossPay);
    out += "\n\t- NetPay: ";
    out += std::to_string(NetPay);
    std::cout << out << std::endl;
    return out;
}

int Employee::setHoursWorked(int hours)
{
    if (hours < 0 || hours > 84)
    {
        std::cout << "Invalid Hours Worked" << std::endl;
        return HoursWorked;
    }
    HoursWorked = hours;
    return HoursWorked;
}

float Employee::setHourlyRate(float rate)
{
    if (rate < 0 || rate > 200)
    {
        std::cout << "Invalid Hourly Rate" << std::endl;
        return HourlyRate;
    }
    HourlyRate = rate;
    return HourlyRate;
}
