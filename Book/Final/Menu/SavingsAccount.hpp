/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SavingsAccount.hpp
 * Author: Victo
 *
 * Created on July 28, 2020, 9:21 PM
 */

#ifndef SAVINGSACCOUNT_HPP
#define SAVINGSACCOUNT_HPP
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
class SavingsAccount {
	public:
		SavingsAccount(float);               //Constructor
		void  Transaction(float);            //Procedure
		float Total(float=0,int=0);	         //Savings Procedure
		float TotalRecursive(float=0,int=0);
		std::string toString();                    //Output Properties
	private:
		float Withdraw(float);               //Utility Procedure
		float Deposit(float);                //Utility Procedure
		float Balance;                       //Property
		int   FreqWithDraw;                  //Property
		int   FreqDeposit;                   //Property

};

#endif /* SAVINGSACCOUNT_HPP */

