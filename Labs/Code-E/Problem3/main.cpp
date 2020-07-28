/* 
 * Author: 
 * Date:
 * Purpose:
 */

//System Libraries Here
#include <iostream>

//User Libraries Here

//Global Constants Only, No Global Variables
//Constants like PI, e, Gravity, Conversions, 2D array size only!

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    
    float total, count = 0;
    std::cout << "Input 5 numbers." <<std::endl;
    for(int i=0;i<5;i++){
        float temp = 0;
        std::cin>>temp;
        
        total += temp;
        count++;
    }
    std::cout << "The average is " << (total/count);
    return 0;
}