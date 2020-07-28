/*
 a) Using a byte variable, what is the largest n where n!=factorial 
that can be calculated.  A factorial is simply 

n! = 1 * 2 * 3 * 4 ... * (n-2) * (n-1) * n

For instance, 1! = 1,  2! = 2,  3! = 6,  4! = 24,  5! = 120 etc....

Signed as well as unsigned for all data types.

b)  What would be the largest factorial using short, int, long, float, 
double, etc...  Use all the primitive data types that you are familiar 
with signed as well as unsigned.

Note:  I want you to investigate this and the program you 
turn in should just print "cout" the final results.  You don't know 
how to capture errors yet so run each till it overflows then back off by 1.
Don't need the program that tests for this.

*/

#include <iostream>
#include <algorithm>
#include <string>

void fact_unsigned_char(){
    unsigned char n= 6;
    unsigned char factorial = 1;
    for(int i = 1; i <=n; ++i)
    {
        factorial *= i;
    }

    std::cout << "Unsigned Byte (char) Max: " <<  std::to_string(n) << " with factorial = " <<  std::to_string(factorial) << std::endl;
}


void fact_signed_char(){
    char n= 5;
    char factorial = 1;
    for(int i = 1; i <=n; ++i)
    {
        factorial *= i;
    }

    std::cout << "Signed Byte (char) Max: " <<  std::to_string(n) << " with factorial = " <<  std::to_string(factorial) << std::endl;
}


void fact_unsigned_short(){
    unsigned short n= 8;
    unsigned short factorial = 1;
    for(int i = 1; i <=n; ++i)
    {
        factorial *= i;
    }

    std::cout << "Unsigned short) Max: " <<  std::to_string(n) << " with factorial = " <<  std::to_string(factorial) << std::endl;
}


void fact_signed_short(){
    short n= 7;
    short factorial = 1;
    for(int i = 1; i <=n; ++i)
    {
        factorial *= i;
    }

    std::cout << "Signed short Max: " <<  std::to_string(n) << " with factorial = " <<  std::to_string(factorial) << std::endl;
}

void fact_unsigned_int(){
    unsigned int n= 17;
    unsigned int factorial = 1;
    for(int i = 1; i <=n; ++i)
    {
        factorial *= i;
    }

    std::cout << "Unsigned int) Max: " <<  std::to_string(n) << " with factorial = " <<  std::to_string(factorial) << std::endl;
}


void fact_signed_int(){
    int n= 16;
    int factorial = 1;
    for(int i = 1; i <=n; ++i)
    {
        factorial *= i;
    }

    std::cout << "Signed int Max: " <<  std::to_string(n) << " with factorial = " <<  std::to_string(factorial) << std::endl;
}



void fact_unsigned_long(){
    unsigned long n= 26;
    unsigned long factorial = 1;
    for(int i = 1; i <=n; ++i)
    {
        factorial *= i;
    }

    std::cout << "Unsigned long) Max: " <<  std::to_string(n) << " with factorial = " <<  std::to_string(factorial) << std::endl;
}


void fact_signed_long(){
    long n= 25;
    long factorial = 1;
    for(int i = 1; i <=n; ++i)
    {
        factorial *= i;
    }

    std::cout << "Signed long Max: " <<  std::to_string(n) << " with factorial = " <<  std::to_string(factorial) << std::endl;
}




void fact_signed_float(){
    float n= 34;
    float factorial = 1;
    for(int i = 1; i <=n; ++i)
    {
        factorial *= i;
    }

    std::cout << "Signed float Max: " <<  std::to_string(n) << " with factorial = " <<  std::to_string(factorial) << std::endl;
}



void fact_signed_double(){
    double n= 170;
    double factorial = 1;
    for(int i = 1; i <=n; ++i)
    {
        factorial *= i;
    }

    std::cout << "Signed double Max: " <<  std::to_string(n) << " with factorial = " <<  std::to_string(factorial) << std::endl;
}


int main(){
    fact_unsigned_char();
    fact_signed_char();

    fact_unsigned_short();
    fact_signed_short();

    fact_unsigned_int();
    fact_signed_int();

    fact_unsigned_long();
    fact_signed_long();
    
    
    fact_signed_float();
    fact_signed_double();
    
    
   
   
    
    


    return 0;
}