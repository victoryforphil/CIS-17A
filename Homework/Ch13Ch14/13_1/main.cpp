#include <string>
#include <iostream>

#include "date.hpp"
int main(){

    Date tstDate;
    int toSet = 0;
    do{
        std::cout << "Please enter a month (1-12): ";
       
        std::cin >> toSet;
    }while(tstDate.SetMonth(toSet));
    std::cout << std::endl;
    do{
        std::cout << "Please enter a day (1-31): ";
       
        std::cin >> toSet;
    }while(tstDate.SetDay(toSet));
     std::cout << std::endl;
    do{
        std::cout << "Please enter a year: ";
        
        std::cin >> toSet;
    }while(tstDate.SetYear(toSet));
     std::cout << std::endl;
    
    std::cout << tstDate.GetMonth() << "/" << tstDate.GetDay() << "/" << tstDate.GetYear() << std::endl;

    return 0;
}