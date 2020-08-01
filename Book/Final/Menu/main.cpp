/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Victo
 *
 * Created on July 31, 2020, 1:48 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include "Prob1Random.hpp"
#include "Prob2Sort.hpp"
#include "Prob3TableInherited.hpp"
#include "Employee.hpp"
#include "SavingsAccount.hpp"
using namespace std;

/*
 * 
 */
void p1();
void p2();
void p3();
void p4();
void p5();
int main(int argc, char **argv)
{

    int choice = 0;
    do
    {
        std::cout << "Please Select A Project 1-5" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            p1();
            break;
        case 2:
            p2();
            break;
        case 3:
            p3();
            break;
        case 4:
            std::cout << "EXTRA CREDIT #1 TO STRING" << std::endl;
            std::cout << "EXTRA CREDIT #1 TO STRING" << std::endl;
            std::cout << "EXTRA CREDIT #1 TO STRING" << std::endl;
            p4();
            break;
        case 5:
            std::cout << "EXTRA CREDIT #1 TO STRING" << std::endl;
            std::cout << "EXTRA CREDIT #1 TO STRING" << std::endl;
            std::cout << "EXTRA CREDIT #1 TO STRING" << std::endl;
            p5();
            break;
        }
        choice = 0;
    } while (choice < 1 || choice > 5);

    return 0;
}

void p1()
{
    char n = 5;
    char rndseq[] = {18, 33, 56, 79, 126};
    int ntimes = 100000;
    Prob1Random a(n, rndseq);
    for (int i = 1; i <= ntimes; i++)
    {
        a.randFromSet();
    }
    int *x = a.getFreq();
    char *y = a.getSet();

    for (int i = 0; i < n; i++)
    {
        cout << int(y[i]) << " occured " << x[i] << " times" << endl;
    }
    cout << "The total number of random numbers is " << a.getNumRand() << endl;
}

void p2()
{
    cout << "The start of Problem 2, the sorting problem" << endl;
    Prob2Sort<char> rc;

    bool ascending = true;
    ifstream infile;
    infile.open("Problem2.txt", ios::in);

    char *ch2 = new char[10 * 16];
    char *ch2p = ch2;

    while (infile.get(*ch2))
    {
        cout << *ch2;
        ch2++;
    }
    
    infile.close();

    cout << endl;
    cout << "Sorting on which column" << endl;

    int column;
    cin >> column;

    char *zc = rc.sortArray(ch2p, 10, 16, column, ascending);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            cout << zc[i * 16 + j];
        }
    }
    
    delete[] zc;
    cout << endl;
}

void p3()
{
    cout << "Entering problem number 3" << endl;
    int rows = 5;
    int cols = 6;
    Prob3TableInherited<int> tab("Problem3.txt", rows, cols);
    const int *naugT = tab.getTable();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << naugT[i * cols + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    const int *augT = tab.getAugTable();
    for (int i = 0; i <= rows; i++)
    {
        for (int j = 0; j <= cols; j++)
        {
            cout << augT[i * (cols + 1) + j] << " ";
        }
        cout << endl;
    }
}
void p4()
{
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
}

void p5()
{
    Employee Mark("Mark", "Boss", 215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0),
                      Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0),
                      Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0),
                      Mark.setHoursWorked(25));
    Mark.toString();

    Employee Mary("Mary", "VP", 50.0);
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
                      Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
                      Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
                      Mary.setHoursWorked(60));
    Mary.toString();
}
