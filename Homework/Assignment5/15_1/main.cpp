#include <iostream>
#include "production_worker.hpp"

int main(){
    ProductionWorker* worker;

    worker = new ProductionWorker("Test Worker", 131313, "4/15/2031", 1, 15.05);

    std::cout << "Worker: \n" 
        << "\t - Name: " << worker->GetName() << "\n" 
        << "\t - Number: " << worker->GetNumber() << "\n" 
        << "\t - Hire Date: " << worker->GetHireDate()  << "\n" 
        << "\t - Shift*: " << worker->GetShift()  << "\n" 
        << "\t - Rate*: " << worker->GetRate() << "\n" 
        << "(* = ProductionWorker Data)" << std::endl;

    std::cout << "---- SIMULATED RAISE AND SHIFT CHANGE ---- " << std::endl;

    worker->SetShift(2);
    worker->SetRate(16.44);
    std::cout << "Worker: \n" 
        << "\t - Name: " << worker->GetName() << "\n" 
        << "\t - Number: " << worker->GetNumber() << "\n" 
        << "\t - Hire Date: " << worker->GetHireDate()  << "\n" 
        << "\t - Shift*: " << worker->GetShift()  << "\n" 
        << "\t - Rate*: " << worker->GetRate() << "\n" 
        << "(* = ProductionWorker Data)" << std::endl;


    delete worker;
}