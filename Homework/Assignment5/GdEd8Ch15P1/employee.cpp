#include "employee.h"

Employee::Employee(std::string name, int num, std::string hireDate) {
    SetName(name);
    SetNumber(num);
    SetHireDate(hireDate);
}

void Employee::SetName(std::string name) {
    m_name = name;
}
void Employee::SetNumber(int num) {
    m_number = num;
}
void Employee::SetHireDate(std::string date) {
    m_hireDate = date;
}

std::string Employee::GetName() {
    return m_name;
}
int Employee::GetNumber() {
    return m_number;
}
std::string Employee::GetHireDate() {
    return m_hireDate;
}