#include <iostream>

template<typename  T>
T GetMax(T a, T b){
    return a>b?a:b;
}

template<typename  T>
T GetMin(T a, T b){
    return a<b?a:b;
}
int main(){

   
    int max = GetMax<int>(9,325);
    float min = GetMin<float>(0.4,0.39999);

    std::cout << "Max between 9, and 325: " << max << std::endl;
    std::cout << "Min between 0.4, and 0.39999: " << min << std::endl;

    return 0;
}