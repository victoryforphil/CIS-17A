#include <iostream>
#include "inventory.hpp"

void print(Inventory& inv){
    std::cout << inv.GetItemNumber << " - Quantity:" << inv.GetQuantity() << " - Cost $" 
    << inv.GetCost() << " - TotalCost: $" << inv.GetTotalCost() << std::endl;
}

int main(){
    Inventory inv(1, 4.5, 141);
    print(inv);

    Inventory invUser;

    int toSet;
    do{
        std::cout << "Enter an item number" << std::endl;
        std::cin >> toSet;
    }while(!invUser.SetItemNumber(toSet));

    do{
        std::cout << "Enter a quantity" << std::endl;
        std::cin >> toSet;
    }while(!invUser.SetQuantity(toSet));

    double toSetDbl;

    do{
        std::cout << "Enter a cost" << std::endl;
        std::cin >> toSetDbl;
    }while(!invUser.SetCost(toSetDbl));

    print(invUser);
    return 0;
}