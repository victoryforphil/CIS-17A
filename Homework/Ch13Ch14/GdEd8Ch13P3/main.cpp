#include <iostream>
#include "car.hpp"

void stats(Car &car){
    std::cout << car.GetYearModel() << " " << 
        car.GetMake() << ": " << car.GetSpeed() << "mph" << std::endl;
}

int main(){
    Car car(2020, "Tesla Model Y");
    stats(car);
    
    for(int i=0;i<5;i++){
        car.Accelerate();
        stats(car);
    }

    for(int i=0;i<5;i++){
        car.Break();
        stats(car);
    }

    return 0;
}