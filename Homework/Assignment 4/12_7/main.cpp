/*
Write a program that asks the user for two file names. The first file will be opened for
input and the second file will be opened for output. (It will be assumed that the first file
contains sentences that end with a period.) The program will read the contents of the first
file and change all the letters to lowercase except the first letter of each sentence, which
should be made uppercase. The revised contents should be stored in the second file. 
*/


    
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
