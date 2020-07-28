/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SavingsAccount.cpp
 * Author: Victo
 * 
 * Created on July 28, 2020, 9:22 PM
 */

#include "SavingsAccount.hpp"

SavingsAccount::SavingsAccount(float balance) {
    Balance = 0;
    if(balance > 0){
        Balance = balance;
    }
    FreqDeposit = 0;
    FreqWithDraw = 0;
}

void SavingsAccount::Transaction(float amount){
    if(amount > 0){
        
        Deposit(amount);
        
    }else{
        
        Withdraw(amount);
        
    }

    
}

float SavingsAccount::Deposit(float amount){
    Balance += amount;
    FreqDeposit++;
    return Balance;
}

float SavingsAccount::Withdraw(float amount){
    if(Balance + amount >= 0){
        Balance = Balance + amount;
        FreqWithDraw++;
    }else{
        std::cout << "WithDraw not Allowed" << std::endl;
    }
    return Balance;
}

void SavingsAccount::toString(){
    std::cout << "Account Statement: " <<
        "\n\t-Balance $: " << Balance << 
        "\n\t-FreqWithDraw $: " << FreqWithDraw << 
        "\n\t-FreqDeposit $: " << FreqDeposit << std::endl;
}

float SavingsAccount::Total(float intrest, int time){

    float tmpBal = Balance;
    for(int i=0;i<time;i++){
        tmpBal +=  tmpBal*intrest;
    }

    return tmpBal;
}
float SavingsAccount::TotalRecursive(float intrest, int time){

    if(time > 0){
        return TotalRecursive(intrest * time, time-1);
    }else{
        return Balance + intrest;
    }
    
}

