#include <iostream>


template <typename T>

T getToal(int amount){
    T total;
    for(int i=0;i<amount;i++){
        T temp;
        std::cout << "Entry #" << i << std::endl;
        std::cin >> temp;
        total += temp;
    }
    return total;
}

int main(){
    std::cout << "Enter 5 ints: " << std::endl;
    int total1 = getToal<int>(5);
    std::cout << "Total: " << total1;

    std::cout << "Enter 5 Floatx: " << std::endl;
    float total2 = getToal<float>(5);
    std::cout << "Total: " << total2;    
    return 0;
}