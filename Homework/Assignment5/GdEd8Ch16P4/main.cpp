#include <iostream>

template<typename  T>
T Abs(T a){
    return a < 0 ? a * -1 : a;
}
int main(){
    
    
    int abs1 = Abs<int>(-31);
    float abs2 = Abs<float>(0.4);

    std::cout << "Abs of -31: " << abs1 << std::endl;
    std::cout << "Abs of 0.4: " << abs2 << std::endl;

    return 0;
}