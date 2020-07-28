#include "car.hpp"

Car::Car(int year, std::string make){
    m_yearModel = year;
    m_make = make;
    m_speed = 0;
}

Car::~Car(){}

int Car::GetYearModel(){return m_yearModel};
std::string Car::GetMake(return m_make);
int Car::GetSpeed(return m_speed);

void Car::Accelerate(){
    m_speed += 5;
}

void Car::Break(){
    if(m_speed >= 5){ // Cant go negative if your breaking
        m_speed += 5;
    }
}

