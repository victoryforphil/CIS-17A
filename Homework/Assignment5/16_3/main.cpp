#include <iostream>
#include "minmax.hpp"

int main(){

    MinMax minMax;
    int max = minMax.GetMax<int>(9,325);
    float min = minMax.GetMin<float>(0.4,0.39999);

    std::cout << "Max between 9, and 325: " << max << std::endl;
    std::cout << "Min between 0.4, and 0.39999: " << min << std::endl;

    return 0;
}