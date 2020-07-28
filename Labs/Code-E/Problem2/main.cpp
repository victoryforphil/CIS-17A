/* 
 * File:
 * Author:
 * Date:
 * Purpose:
 * Version:
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    

    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    
    //Initialize or input data here
    
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
    
    //Clean up allocated memory here
    
    //Exit stage left
    
    for(int i=0;i<4;i++){
        double entry;
        cin >> entry;
        cout << fixed << setw(9);
        
        cout << setprecision(0) << entry;
        cout << fixed << setw(10);
        cout << setprecision(1) << entry;
        cout << fixed << setw(10);
        cout << setprecision(2) << entry;
       
        if(i != 3){
            cout << endl;
        }
    }
    return 0;
}