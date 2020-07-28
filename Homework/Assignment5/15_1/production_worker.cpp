#include "production_worker.hpp"

ProductionWorker::ProductionWorker(std::string name, int num, std::string hireDate, int shift, int rate)
    : Employee(name, num, hireDate)
{
    SetShift(shift);
    SetRate(rate);
}

void ProductionWorker::SetShift(int shift){
    m_shift = shift;
}
void ProductionWorker::SetRate(double rate){
    m_rate = rate;
}

int ProductionWorker::GetShift(){
    return m_shift;
}
double ProductionWorker::GetRate(){
    return m_rate;
}
