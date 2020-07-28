#include <iostream>
#include "miltime.hpp"


int main(){

    MilTime time;

    try{
        time.SetTime(3243,30);
    }catch(BadHour ex){
        std::cout << "Error In Time: " << ex.what() << std::endl;
    }catch(BadSeconds ex){
        std::cout << "Error In Secs: " << ex.what() << std::endl;
    }
    
    try{
        time.SetTime(1333,80);
    }catch(BadHour ex){
        std::cout << "Error In Time: " << ex.what() << std::endl;
    }catch(BadSeconds ex){
        std::cout << "Error In Secs: " << ex.what() << std::endl;
    }

  
    return 0;
}