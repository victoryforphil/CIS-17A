#include "personal_info.hpp"

PersonalInfo::PersonalInfo()
{
    m_age = 1;
    m_name = "N/A";
    m_addr = "N/A";
    m_phone = "N/A";
}

bool PersonalInfo::SetName(std::string name)
{
    if (name != "")
    {
        m_name = name;
        return true;
    }
    else
    {
        return false;
    }
}

bool PersonalInfo::SetAddr(std::string addr)
{
    if (addr != "")
    {
        m_addr = addr;
        return true;
    }
    else
    {
        return false;
    }
}

bool PersonalInfo::SetPhone(std::string phone)
{
    if (phone != "")
    {
        m_phone = phone;
        return true;
    }
    else
    {
        return false;
    }
}

bool PersonalInfo::SetAge(int age)
{
    if (age >= 0 && age <= 200)
    {
        m_age = age;
        return true;
    }
    else
    {
        return false;
    }
}

std::string PersonalInfo::GetName(){
    return m_name;
}
std::string PersonalInfo::GetAddress(){
    return m_addr;
}
int PersonalInfo::GetAge(){
    return m_age;
}
std::string PersonalInfo::GetPhone(){
    return m_phone;
}

PersonalInfo::~PersonalInfo()
{
}