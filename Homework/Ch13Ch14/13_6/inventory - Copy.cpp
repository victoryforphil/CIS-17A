#include "inventory.hpp"

Inventory::Inventory()
{
    SetCost(0);
    SetItemNumber(0);
    SetQuantity(0);
}

Inventory::Inventory(int itemNum, double cost, int quantity)
{
    SetItemNumber(itemNum);
    SetCost(cost);
    SetQuantity(quantity);
    SetTotalCost();
}

bool Inventory::SetItemNumber(int itemNum){
    if(itemNum > 0){
        m_itemNum = itemNum;
        return true;
    }else{
        return false;
    }

}
bool Inventory::SetQuantity(int quantity){
    if(quantity > 0){
        m_quantity = quantity;
        return true;
    }else{
        return false;
    }
}
bool Inventory::SetCost(double cost){
    if(cost > 0){
        m_cost = cost;
        return true;
    }else{
        return false;
    }
}

void Inventory::SetTotalCost(){
    m_totalCost = m_cost * m_quantity;
}

int Inventory::GetItemNumber(){
    return m_itemNum;
}
int Inventory::GetQuantity(){
    return m_quantity;
}
double Inventory::GetCost(){
    return m_cost;
}
double Inventory::GetTotalCost(){
    return m_totalCost;
}