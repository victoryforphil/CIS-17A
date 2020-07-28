#ifndef _CAR_H_
#define _CAR_H_
#include <string>

class Car
{
private:
    int m_yearModel;
    std::string m_make;
    int m_speed;

public:
    Car(int year, int make);
    int GetYearModel();
    std::string GetMake();
    int GetSpeed();

    void Accelerate();
    void Break();
    ~Car();
};

#endif