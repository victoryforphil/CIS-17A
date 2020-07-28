/* 
 * Assignment: Review Homework 1
 * SubAssignemnt: 3.13
 * Author: Alex Carter
 * Created on 6/29/2020
 */


// Import
#include <cstdlib>
#include <iostream>
#include <iomanip>


int main() {
    //Define Consts
    const float YEN_PER_DOLLAR   = 98.93;
    const float EUROS_PER_DOLLAR = 0.74;
    
    float usdIn = 0; // Var to read into

    //Get Input USD Amount and save into usdIn
    std::cout << "Enter USD Amount: " << std::endl;
    std::cin >> usdIn;

    // Print Conversions (Conversion occur in-line)
    std::cout << std::fixed << std::setprecision(2) << "YEN: " << dollarIn * YEN_PER_DOLLAR << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "EURO: " << dollarIn* EUROS_PER_DOLLAR << std::endl;
    return 0;
}

