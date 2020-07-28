#ifndef _INVENTORY_H_
#define _INVENTORY_H_

class Inventory
{
private:
    int m_itemNum;
    int m_quantity;
    double m_cost;
    double m_totalCost; 

public:
    Inventory();
    Inventory(int itemNum, double cost, int quantity);

    bool SetItemNumber(int itemNum);
    bool SetQuantity(int quantity);
    bool SetCost(double cost);
    void SetTotalCost();

    int GetItemNumber();
    int GetQuantity();
    double GetCost();
    double GetTotalCost();

    //~Inventory();
};



#endif