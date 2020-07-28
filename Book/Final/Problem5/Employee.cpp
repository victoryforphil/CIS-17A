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

Employee::Employee(char[] name, char[] title, float rate) {
    MyName = name;
    JobTitle = title
    HourlyRate = rate;
    HoursWorked  =0;
    GrossPay = 0.0;
    NetPay = 0.0;
}

double Employee::Tax(float amount){
    float rate = 0.1;
    if(GrossPay)
}


