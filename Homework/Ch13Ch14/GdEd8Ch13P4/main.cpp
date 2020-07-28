#include <string>
#include <iostream>
#include "personal_info.hpp"


void prnt(PersonalInfo &info){
    std::cout << "Personal Info: " << std::endl;
    std::cout <<    "\t- Name: " << info.GetName() << std::endl;
    std::cout <<    "\t- Age: " << info.GetAge() << std::endl;
    std::cout <<    "\t- Address: " << info.GetAddress() << std::endl;
    std::cout <<    "\t- Phone: " << info.GetPhone() << std::endl;
}

int main(){

    PersonalInfo myInfo;
    PersonalInfo moInfo;
    PersonalInfo faInfo;


    myInfo.SetAddr("9931 32nd St, Portland OR");
    myInfo.SetName("Alex Carter");
    myInfo.SetAge(19);
    myInfo.SetPhone("555-333-1113");

    moInfo.SetAddr("9931 32nd St, IDk where OR");
    moInfo.SetName("Anita Carter");
    moInfo.SetAge(43);
    moInfo.SetPhone("555-444-1113");

    faInfo.SetAddr("9931 32nd St, Eugne OR");
    faInfo.SetName("Ryan Carter");
    faInfo.SetAge(52);
    faInfo.SetPhone("555-666-1113");

    prnt(myInfo);
    prnt(moInfo);
    prnt(faInfo);
    return 0;
}