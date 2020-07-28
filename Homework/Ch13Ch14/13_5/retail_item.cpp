#include "retail_item.hpp"

RetailItem::RetailItem(std::string desc, int units, double price)
{
    SetDesc(desc);
    SetPrice(price);
    SetUnits(units);
}

void RetailItem::SetDesc(std::string desc){
    m_desc = desc;
}
void RetailItem::SetUnits(int units){
    m_units = units;
}
void RetailItem::SetPrice(double price){
    m_price = price;
}

std::string RetailItem::GetDesc(){
    return m_desc;
}
int RetailItem::GetUnits(){
    return m_units;
}
double RetailItem::GetPrice(){
    return m_price;
}

RetailItem::~RetailItem()
{
}
