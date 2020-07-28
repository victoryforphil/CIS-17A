/* 
 * Assignment: Review Homework 1
 * SubAssignemnt: 4.10
 * Author: Alex Carter
 * Created on 6/29/2020
 */

//Imports
#include <iostream>

int main() {
    
    int month, year = 0;

    do{
        std::cout << "Enter a month (1-12): " << std::endl;
        std::cin >> month;
    }while(month < 0 || month > 13);
    
    std::cout << "Enter a year: " << std::endl;
    std::cin >> year;
    
    int days = 31;
    if(month % 2 == 0){
        days = 30;
    }
    
    if(month == 2){
        days = 28; // Feb.
    }
    
    bool leap = false;
    leap = year % 100 == 0;
    leap = leap || year % 400 == 0;
    leap = leap || year % 100 != 0 && year % 4 == 0; 
    
    if(leap && month == 2){
        days = 29;
    }
    std::cout << "Number of days: " << days; 
    return 0;
}

