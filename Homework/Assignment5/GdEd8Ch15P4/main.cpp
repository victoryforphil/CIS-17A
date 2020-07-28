#include <iostream>
#include "miltime.hpp"


int main(){
    
    std::cout << "Generaterd MilTime Conversion (1350, 13s)" << std::endl;
    MilTime m1(1350, 13);
    std::cout << "Result: " << m1.getHour() 
        << ":"<<m1.getMin() << ":" << m1.getSec() << std::endl;

    std::cout << "Enter Mil Time to convert: " << std::endl;
    
    MilTime m2;
    int inputHours = 0;
    int inputSecs = 0;
    do{
        std::cout << "\t - Hours: ";
        std::cin >> inputHours;
        std::cout << std::endl << "\t - Secs:";
        std::cin >> inputSecs;
        std::cout << std::endl; 
    }while(!m2.SetTime(inputHours, inputSecs));

     std::cout << "Result: " << m1.getHour() 
        << ":"<<m1.getMin() << ":" << m1.getSec() << std::endl;
}