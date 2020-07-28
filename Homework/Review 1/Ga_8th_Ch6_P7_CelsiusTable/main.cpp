/* 
 * Assignment: Review Homework 1
 * SubAssignemnt: 6.7
 * Author: Alex Carter
 * Created on 6/29/2020
 */

//Imports

#include <cstdlib>
#include <iostream>
#include <iomanip>

int celsius(int temp){
    return (temp-32) * 0.555555555555555555;
}

int main() {
    std::cout << "F -> C " << std::endl;
    for(int i=0;i<=20;i++){
        std::cout << i << "    " <<celsius(i) << std::endl;
    }
    return 0;
}

