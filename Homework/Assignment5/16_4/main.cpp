#include <iostream>
#include "absolute.hpp"

int main(){

    Absolute abs;
    int abs1 = abs.Abs<int>(-31);
    float abs2 = abs.Abs<float>(0.4);

    std::cout << "Abs of -31: " << abs1 << std::endl;
    std::cout << "Abs of 0.4: " << abs2 << std::endl;

    return 0;
}