#include <iostream>
#include "dayofyear.hpp"


int main(){
    
    int toSet=0;
    do{
        std::cout << "Enter a valid positive integer:";
        std::cin >> toSet;
    }while(toSet <= 0);

    DayOfYear num(toSet);
    num.print();
    return 0;
}