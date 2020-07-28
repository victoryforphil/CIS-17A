/* 
 * Assignment: Review Homework 1
 * SubAssignemnt: 5.11
 * Author: Alex Carter
 * Created on 6/29/2020
 */

//Imports

#include <cstdlib>
#include <iostream>

int main() {
    int pop, days = 0;
    float rate = 0;
    
    do{
        std::cout << "Enter Population Size: " << std::endl;
        std::cin >> pop;
    }while(pop < 2);
    
    do{
        std::cout << "Enter Population Growth rate as a decimal: " << std::endl;
        std::cin >> rate;
    }while(rate <= 0);
    
    do{
        std::cout << "Enter how long to simulate: " << std::endl;
        std::cin >> days;
    }while(days < 1);
    

    for(int i=0;i<days;i++){
        pop += pop * rate;
    }
    
    std::cout << "Final Population: " << pop;
    return 0;
}

