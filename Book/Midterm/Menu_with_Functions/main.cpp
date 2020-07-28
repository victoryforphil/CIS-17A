/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on April 17th, 2020, 10:20 AM
 * Purpose:  Menu using Functions,
 *           extend for midterm
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
void prblm7();

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='4');
    
    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Menu
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 1
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
struct Customer
{
    std::string name;
    std::string addr;
    unsigned int startBal;
    unsigned int accNum;
    unsigned int totChecks;
    unsigned int totDepo;

};

void inputData(Customer* out){
    do{
        std::cout << "Please enter your full name (> 2 characters): " << std::endl;
        std::cin >> out->name;
    }while(strlen(out->name.c_str()) < 2); // Loop until name > 2 character long

    do{
        std::cout << "Please enter account address:" << std::endl;
        std::cin >> out->addr;
    }while(strlen(out->addr.c_str()) < 5); // Loop until name > 5 character long

    do{
        std::cout << "Please enter account starting balance: " << std::endl;
        std::cin >> out->startBal;
    }while(out->startBal < 0); // Loop while bal is negative

    bool bDone=false;
    while(!bDone){
        std::string input;
        std::cout << "Enter a check (enter q to finish): ";
        std::cin >> input;
        if(strlen(input.c_str()) < 1 || input == "q"){
            bDone = true;
        }else{
            out->totChecks += std::stoi(input);
            std::cout << "Check Added, new check total: " << out->totChecks << std::endl;
        }
        
    }
    
    bDone = false;

    while(!bDone){
        std::string input;
        std::cout << "Enter a deposit (enter q to finish): ";
        std::cin >> input;
        if(strlen(input.c_str()) < 1 || input == "q"){
            bDone = true;
        }else{
            out->totDepo += std::stoi(input);
            std::cout << "Check Added, new deposit total: " << out->totDepo << std::endl;
        }
        
    }
    
}
void prblm1(){
    cout<<"Problem 1"<<endl;
    Customer* customer;

    customer = new Customer();
    std::cout << "[Collecting Account Information]" << std::endl;
    inputData(customer);
    std::cout << std::endl << "[Computing new balace]" << std::endl;

    int newBal = customer->startBal;
    newBal     -= customer->totChecks;
    newBal     += customer->totDepo;
    bool overDraft = newBal < 0;
    newBal     -= overDraft?20:0;


    std::cout << std::endl << "[Displaying Customer Information]" << std::endl;

    std::cout << "Account Name: " << customer->name <<std::endl;
    std::cout << "Account Address: " << customer->addr <<std::endl;
    if(overDraft){
        std::cout << "ACCOUNT OVERDRAFTED, $20 FEE"  <<std::endl;
        std::cout << "Account Balance w/ Fee: "<< newBal + 20  <<std::endl;
    }
    std::cout << "Account Starting Balance: " << customer->startBal <<std::endl;
    std::cout << "Account Ending Balance: " << newBal <<std::endl;
    std::cout << "Account Total Checks (-bal): " << customer->totChecks <<std::endl;
    std::cout << "Account Total Deposits (+bal): " << customer->totDepo <<std::endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 2
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
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

void prblm2(){
    cout<<"Problem 2"<<endl;
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

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 3
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm3(){
    cout<<"Problem 3 Included Elsewhere"<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 4
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890

void getData(int (&out)[4]){
    std::string valRaw;
    std::cin >> valRaw;

    out[0] = (int)valRaw[0]-48;
    out[1] = (int)valRaw[1]-48;
    out[2] = (int)valRaw[2]-48;
    out[3] = (int)valRaw[3]-48;


}

void encrypt(int (&data)[4]){
    //Replace each digit by (the sum of that digit plus 5 modulus 8. 
    for(int i=0;i<4;i++){
        data[i] = data[i] + (5%8);
    }
    //Then swap the first digit with the third, 
    int temp = data[0];
    data[0] = data[2];
    data[2] = temp;

    //swap the second digit with the fourth
    temp = data[1];
    data[1] = data[3];
    data[3] = temp;
}

void decrypt(int (&data)[4]){
    
    //Then swap the first digit with the third, 
    int temp = data[0];
    data[0] = data[2];
    data[2] = temp;

    //swap the second digit with the fourth
    temp = data[1];
    data[1] = data[3];
    data[3] = temp;

    //Replace each digit by (the sum of that digit plus 5 modulus 8. 
    for(int i=0;i<4;i++){
        data[i] = data[i] - (5%8);
    }
}

void prblm4(){
    cout<<"problem 4"<<endl;
    
    int values[4];
    std::cout << "Enter code: " << std::endl;
    getData(values);

    std::cout << "Code Before Encryption: ";
    for(int i=0;i<4;i++){
        std::cout << values[i] << " ";
        if(values[i] > 7){
            std::cout << "ERROR, NON VALID RANGE (0-7) DETECTED! Canceling operation.";
            return;
        }
    }

    std::cout << std::endl;

    encrypt(values);
    std::cout << "Code After Encryption: ";
    for(int i=0;i<4;i++){
        std::cout << values[i] << " ";;
    }

    std::cout << std::endl;

    decrypt(values);
    std::cout << "Code After Decryption: ";
    for(int i=0;i<4;i++){
        std::cout << values[i] << " ";

        if(values[i] > 7){
            std::cout << "ERROR, NON VALID RANGE (0-7) DETECTED! Canceling operation.";
            return;
        }
    }

    std::cout << std::endl;
}

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
void prblm5(){
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
}

/*
7) Factor an input integer into it's prime numbers.  Create a 
structure to hold the array of prime numbers.  Any number between
[2,10000] will be a valid number to check for prime factors.

struct Prime{
	unsigned short prime;
	unsigned char power;
};
struct Primes{
	unsigned char nPrimes;
	Prime *prime;
};

Output the number and it's primes -> 120 = 2^3 * 3^1 * 5^1
So create a function 

Primes *factor(int);-> Input an integer, return all prime factors
void prntPrm(Primes *); -> Output all prime factors
*/

#include <iostream>
#include <math.h>

struct Prime
{
	unsigned short prime;
	unsigned char power;
};
struct Primes
{
	unsigned char nPrimes;
	Prime *prime;
};

Primes *factor(int);	//-> Input an integer, return all prime factors
void prntPrm(Primes *); // -> Output all prime factors

Primes *factor(int num)
{
	Primes* allPrime = new Primes;
	allPrime->prime = new Prime[3];
	allPrime->nPrimes = 3;

	Prime power2;
	power2.prime = 2;
	while (num % 2 == 0)
	{
		power2.power += 1;
		//std::cout << "2\t";
		num = num / 2;
	}
	allPrime->prime[0] = power2;

	int count=1;
	for (int i = 3; i <= std::sqrt(num); i = i + 2)
	{
		
		while (num % i == 0)
		{
			Prime p;
			p.prime = i;
			p.power = 1;
			//std::cout << i << "\t";
			num = num / i;
			allPrime->prime[count] = p;
			count++;
		}
	}
	if (num > 2){
		Prime p;
		p.prime = num;
		p.power = 1;
		allPrime->prime[count] = p;
	}
	return allPrime;
	//std::cout << num << " ****\t";
}

void prntPrm(Primes *toPrint)
{
	for(int i=0;i<toPrint->nPrimes;i++){
		std::cout << toPrint->prime[i].prime << "^" <<( toPrint->prime[i].power + 0) << " * ";
	}
	
}
void prblm6(){
    /*
    2.875 
Binary  00111000000000000000000000000000      
Oct     7000000000
Hex     38000000

0.1796875 E: 1111 10  Sig 011 1000 0000 0000 0000 0000
Binary 00111000000000000000000001111100
Oct 7000000174
Hex 3800007C
*/
    std::cout << "2.875: " << std::endl;
    std::cout << "\tBinary  00111000000000000000000000000000" << std::endl;
    std::cout << "\tOct     7000000000" << std::endl;
    std::cout << "\tHex     38000000" << std::endl;

    std::cout << "0.1796875: " << std::endl;
    std::cout << "\tBinary  00111000000000000000000001111100" << std::endl;
    std::cout << "\tOct     7000000174" << std::endl;
    std::cout << "\tHex     3800007C" << std::endl;

    std::cout << "-2.875: " << std::endl;
    std::cout << "\tBinary  10111000000000000000000000000000" << std::endl;
    std::cout << "\tOct     27000000000" << std::endl;
    std::cout << "\tHex     B8000000" << std::endl;

    std::cout << "-0.1796875: " << std::endl;
    std::cout << "\tBinary  10111000000000000000000001111100" << std::endl;
    std::cout << "\tOct     27000000174" << std::endl;
    std::cout << "\tHex     B800007C" << std::endl;
    
}
void prblm7(){
    int toFact = 0;
	std::cout << "Enter Number: " <<std::endl;
	std::cin >> toFact;
	prntPrm(factor(toFact));

}