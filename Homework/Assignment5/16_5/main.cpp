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
}

int main(){
    std::cout << "Enter 5 ints: " << std::endl;
    int total = getToal<int>(5);
    std::cout << "Total: " << total;

    std::cout << "Enter 5 Floatx: " << std::endl;
    float total = getToal<float>(5);
    std::cout << "Total: " << total;    
    return 0;
}