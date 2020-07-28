/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Victo
 *
 * Created on July 28, 2020, 9:19 PM
 */

#include <cstdlib>
#include "SavingsAccount.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    SavingsAccount mine(-300);

	for(int i=1;i<=10;i++)
	{
		mine.Transaction((float)(rand()%500)*(rand()%3-1));
	}
	mine.toString();
	cout<<"Balance after 7 years given 10% interest = "
		<<mine.Total((float)(0.10),7)<<endl;

        
	cout<<"Balance after 7 years given 10% interest = "
		<<mine.TotalRecursive((float)(0.10),7)
		<<" Recursive Calculation "<<endl;
    return 0;
}

