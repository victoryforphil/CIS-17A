/*
Develop an application using an array of structures that will 
determine the gross pay for any number of employees input. 
The company pays "straight-time" for the first 40 hours worked, double time for 
all hours worked in excess of 40 hours but less than 50 hours, 
and triple time for any hours worked over 50 hours.

The program should be able to loop and input the employee's name, 
hours worked, and the rate of pay.  Once this has been done then output
this information including the gross pay in the form of a paycheck.

The process starts all over again until you input an invalid rate of pay or hours worked.  This
means a negative rate of pay or negative number of hours worked is
not acceptable.

Print it out like an actual paycheck with English
language representing the check amount.
Printout like a company Paycheck with format:
     Company
     Address
     Name:	
     Amount: numerical
     Amount:  English of numerical value
     Signature Line:
     */

#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <algorithm>

struct Paycheck
{
    std::string company;
    std::string name;
    std::string address;

    float rate;
    int hours;
    int pay;
};

void fillCompanyInfo(Paycheck *out)
{
    out->company = "ROPOC SYSTEMS";
    out->address = "555 Airport Way. San Bernardino CA 92408";
}

bool getInfo(Paycheck *out)
{
    do
    {
        std::cout << "Employee Name: " << std::endl;
        std::cin >> out->name;
    } while (strlen(out->name.c_str()) < 2); // Loop until name > 2 character long

    std::cout << "Pay Rate:" << std::endl;
    std::cin >> out->rate;

    if (out->rate < 0)
    {
        std::cout << "\t - Invalid Pay Rate! Exiting..." << std::endl;
        return true;
    }

    std::cout << "Hours Worked:" << std::endl;
    std::cin >> out->hours;
    if (out->hours < 0)
    {
        std::cout << "\t - Invalid Hours! Exiting..." << std::endl;
        return true;
    }

    return false;
}

/*
Example math:
1) Normal
    Rate = 10.00, hours = 40, total = 400

2) High
    Rate = 10, hours = 60, (40 * 10 == 400, 10 * 20 = 200, 10*30 = 300) = 900

*/
void calculatePay(Paycheck *out)
{
    int baseHours = std::min(out->hours, 40);
    //std::cout << "\t - baseHours: " << baseHours << std::endl;
    int doubleHours = std::min(std::max(0, (out->hours) - 40), 10); // 40-50 range
    //std::cout << "\t - doubleHours: " << doubleHours << std::endl;
    int tripleHours = std::max(0, (out->hours) - 50);
    //std::cout << "\t - tripleHours: " << tripleHours << std::endl;
    out->pay = (out->rate * baseHours) + ((out->rate * 2) * doubleHours) + ((out->rate * 3) * tripleHours);
}

std::string getNumeral(int number)
{
    return "Lol idk";
}

void printCheck(Paycheck *out)
{

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Company: " << out->company << std::endl;
    std::cout << "Address: " << out->address << std::endl;
    std::cout << "Name:    " << out->name << std::endl;
    std::cout << "Amount:  " << out->pay << std::endl;
    std::cout << "Amount:  " << getNumeral(out->pay) << std::endl;
    std::cout << "Signature: "
              << "x_______________________" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl
              << std::endl;
}

int main()
{
    int size = 0;
    Paycheck *array = new Paycheck[1];

    bool isDone;

    while (!isDone)
    {
        std::cout << std::endl;
        Paycheck *newPay = new Paycheck();
        fillCompanyInfo(newPay);
        isDone = getInfo(newPay);
        calculatePay(newPay);
        if (!isDone)
        {
            size++;
            Paycheck *temp = new Paycheck[size];
            std::copy(array, array + (size - 1), temp);
            delete[] array;
            array = temp;
            array[size - 1] = *newPay;
        }
    }

    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += array[i].pay;
        printCheck(&array[i]);
        std::cout << "Total Staff Cost: " << total;
    }
}