#ifndef _PERSONAL_INFO_H_
#define _PERSONAL_INFO_H_


#include <string>

class PersonalInfo
{
private:
    std::string m_name;
    std::string m_addr;
    int m_age;
    std::string m_phone;


public:
    PersonalInfo(/* args */);
    bool SetName(std::string name);
    bool SetAddr(std::string addr);
    bool SetAge(int age);
    bool SetPhone(std::string phone);

    std::string GetName();
    std::string GetAddress();
    int GetAge();
    std::string GetPhone();

    ~PersonalInfo();
};



#endif