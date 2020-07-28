/*
1)  Develop an application using structures for a customer
that will determine if he/she has exceeded his/her checking 
account balance. For each customer, the following 
facts are available:

a. Name
b. Address
c. Account number (Five digits only, i.e. test for this)
d. Balance at the beginning of the month 
e. Total of all checks written by this customer this month 
     Loop until customer is through entering checks.
f. Total of all deposits credited to this customer's account this 
     month.  Loop until customer is through entering deposits.

Dynamically create the structure.
The program should input each of these facts from input dialogs,
store in a structure, calculate the new balance, 
display the new balance and debit the account $20 if overdrawn. 
Also, if overdrawn, tell the customer the additional $20 fee 
has been accessed and what the balance would be with this fee included.
Make sure to output the contents of the structure.

*/

#include <string>
#include <iostream>
#include <iomanip>
#include <cstring>
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

int main(){
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