#include "essay.hpp"
#include <iostream>
int main(){

    Essay essay1;

    essay1.SetContent(15);
    essay1.SetGrammer(25);
    essay1.SetLength(20);
    essay1.SetSpelling(19);

    std::cout << "Essay #1 Score: " << essay1.getScore() << std::endl;

    Essay essay2;

    essay2.SetContent(30);
    essay2.SetGrammer(30);
    essay2.SetLength(20);
    essay2.SetSpelling(20);

    std::cout << "Essay #2 Score: " << essay2.getScore() << std::endl;

    return 0;
}