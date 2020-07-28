#include <iostream>
#include "retail_item.hpp"

void prnt(int idx, RetailItem &item)
{
    std::cout << "Item #" << idx << " " << item.GetDesc() << "\n\t" << item.GetUnits() << "\n\t" << item.GetPrice();
}

int main()
{

    RetailItem i1("Jacket", 12, 59.95);
    RetailItem i2("Designer Jeans", 40, 34.95);
    RetailItem i3("Shirt", 20, 24.95);
    prnt(1, i1);
    std::cout << std::endl;
    prnt(2, i2);
    std::cout << std::endl;
    prnt(3, i3);
    std::cout << std::endl;
    return 0;
}