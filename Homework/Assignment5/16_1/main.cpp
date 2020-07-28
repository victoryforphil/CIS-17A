#include <iostream>
#include "date.hpp"

int main(){

    Date date;

    try{
        date.SetMonth(13);
        date.SetDay(43);
    }catch(InvalidMonth ex){
        std::cout << "Error In Month: " << ex.what() << std::endl;
    }catch(InvalidDay ex){
        std::cout << "Error In Day: " << ex.what() << std::endl;
    }

    try{
        date.SetMonth(13);
        date.SetDay(43);
    }catch(InvalidMonth ex){
        std::cout << "Error In Month: " << ex.what() << std::endl;
    }catch(InvalidDay ex){
        std::cout << "Error In Day: " << ex.what() << std::endl;
    }
    return 0;
}