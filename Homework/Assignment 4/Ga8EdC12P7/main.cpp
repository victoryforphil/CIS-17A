

    
#include <iostream>
#include <string>
#include <fstream>
#include <locale>  
int main()
{
    
    std::string pathIn = "input.txt";
    std::cout << "Enter Input Path: " << std::endl;
    std::cin >> pathIn;

    std::ifstream inFile;
    inFile.open(pathIn);

    
    std::ofstream outFile;
    std::string pathOut = "out.txt";
    std::cout << "Enter Output Path: " << std::endl;
    std::cin >> pathOut;
    outFile.open(pathOut);


    while (!inFile.eof())
    {
        std::locale loc;
        std::string sent;
        std::getline(inFile, sent);
        sent[0] = std::toupper(sent[0],loc);

        for(int i=1;i<sent.length();i++){
            sent[i] = std::tolower(sent[i],loc);
        }
        std::cout << "After: " << sent << std::endl;
        outFile.write(sent.c_str(), sent.size());
        
        
        
    }

   
    inFile.close();
    return 0;
}
