/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.hpp
 * Author: Victo
 *
 * Created on July 28, 2020, 9:21 PM
 */

#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

class Employee {
public:
		Employee(char[],char[],float);  //Constructor
		float  CalculatePay(float,int); //Procedure
		float  getGrossPay(float,int);  //Procedure
		float  getNetPay(float);        //Procedure
		void   toString();              //Procedure
		int    setHoursWorked(int);     //Procedure
		float  setHourlyRate(float);    //Procedure
	private:
		double Tax(float);      //Utility Procedure
		char   MyName[20];      //Property
		char   JobTitle[20];    //Property
		float  HourlyRate;      //Property
		int    HoursWorked;     //Property
		float  GrossPay;        //Property
		float  NetPay;          //Property

};

#endif /* EMPLOYEE_HPP */

