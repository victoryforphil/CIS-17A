#ifndef _RETAIL_ITEM_H_
#define _REATIL_ITEM_H_

#include <string>

class RetailItem
{
private:
    std::string m_desc;
    int m_units;
    double m_price;
public:
    RetailItem(std::string desc, int units, double price);
    void SetDesc(std::string desc);
    void SetUnits(int units);
    void SetPrice(double price);

    std::string GetDesc();
    int GetUnits();
    double GetPrice();
    ~RetailItem();
};


#endif