/* 
 * File:   main.cpp
 * Author: Alexander Carter
 * Created on 2/16/2020
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction 
 */

//System Libraries Here
#include <iostream> //cin,cout,endl
#include <cstring>  //strlen()
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool inRange(const char[], unsigned short &); //Output true,unsigned or false
bool reverse(unsigned short, signed short &); //Output true,short or false
short subtrct(signed short, int);

//Program Execution Begins Here
int main(int argc, char **argv)
{
    //Declare all Variables Here
    const int SIZE = 80;    //More than enough
    char digits[SIZE];      //Character digits or not
    unsigned short unShort; //Unsigned short
    short snShort;          //Signed short

    //Input or initialize values Here
    cout << "Reverse a number and subtract if possible." << endl;
    cout << "Input a number in the range of an unsigned short" << endl;
    cin >> digits;

    //Test if it is in the Range of an unsigned short
    if (!inRange(digits, unShort))
    {
        cout << "No Conversion Possible" << endl;
        return 0;
    }

    //Reverse and see if it falls in the range of an signed short
    if (!reverse(unShort, snShort))
    {
        cout << "No Conversion Possible" << endl;
        return 0;
    }

    //Now subtract if the result is not negative else don't subtract
    if (snShort > 0)
    {
        snShort = subtrct(snShort, 999);
    }

    //Output the result
    cout << snShort << endl;

    //Exit
    return 0;
}

bool inRange(const char input[], unsigned short &unShort)
{
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] >= '9')
        { // ASCII goes 0-9, A-Z, so >9 is non numbers

            return false;
        }
    }

    int number = std::stoi(input);
    if (number <= 65535 && number >= 0)
    {
        unShort = number;
        return true;
    }
    else
    {
        return false;
    }

} //Output true,unsigned or false

bool reverse(unsigned short a, signed short &b)
{
    short rem;
    int reversed = 0;
    while (a != 0)
    {
        rem = a % 10;
        reversed = reversed * 10 + rem;
        a /= 10;
    }
    //cout << "Before: " << reversed << std::endl;
    if (reversed < 9999)
    {
        if (reversed < 999)
        {
            if (reversed < 99)
            {
                reversed *= 1000;
            }
            else
            {
                reversed *= 100;
            }
        }
        else
        {
           // reversed *= 10;
        }
    }

    //cout << "after: " << reversed << std::endl;
    if (reversed < (65535 / 2))
    {
        b = reversed;
        return true;
    }
    else
    {
        return false;
    }

    return true;
} //Output true,short or false

short subtrct(signed short snShort, int val)
{
    return snShort - val;
}
