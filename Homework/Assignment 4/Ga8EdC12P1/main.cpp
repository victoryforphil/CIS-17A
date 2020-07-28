
#include <iostream>
#include <string>
#include <fstream>

int main()
{
    
    std::string path;
    std::cout << "Enter File Path: " << std::endl;
    std::cin >> path;

    std::ifstream inFile;
    inFile.open(path);

    int lineCt =0 ;
    while (!inFile.eof() && lineCt < 10)
    {
        std::string toPrint;
        std::getline(inFile, toPrint);
        std::cout << toPrint << std::endl;
        lineCt++;
    }

    if(lineCt < 10){
        std::cout << "Entire file was displayed!";
    }

    inFile.close();
    return 0;
}