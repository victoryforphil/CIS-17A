#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>

class Employee
{
private:
    std::string m_name;
    int m_number;
    std::string m_hireDate;
public:
    Employee(std::string name, int num, std::string hireDate);

    void SetName(std::string);
    void SetNumber(int num);
    void SetHireDate(std::string);

    std::string GetName();
    int         GetNumber();
    std::string GetHireDate();

}; 




#endif