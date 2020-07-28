#ifndef _PROD_WORKER_H_
#define _PROD_WORKER_H_

#include "employee.h"

class ProductionWorker :public  Employee
{
private:
    int m_shift; // 1 day, 2 night
    double m_rate;
public:
    ProductionWorker(std::string name, int num, std::string hireDate, 
        int shift, int rate);
    

    void SetShift(int shift);
    void SetRate(double rate);

    int GetShift();
    double GetRate();
};




#endif