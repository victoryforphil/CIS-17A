/*
4. Tail Program
Write a program that asks the user for the name of a file. The program should display
the last 10 lines of the file on the screen (the “tail” of the file). If the file has fewer than
10 lines, the entire file should be displayed, with a message indicating the entire file
has been displayed. 

*/

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

    std::string lines[10];

    while (!inFile.eof())
    {
       
        std::string toPrint;
        
       
        if(lineCt < 10){
           lineCt++;
        }else{
            // Remove first element, shift array left
            for(int i=1;i<10;i++){
                lines[i-1] = lines[i]; 
            }
        }
       
        std::getline(inFile, lines[lineCt - 1]);
        
    }

    for(int i=0;i<lineCt;i++){
       std::cout << lines[i] << std::endl;
    }
    if(lineCt < 10){
        std::cout << "Entire file was displayed!";
    }

    inFile.close();
    return 0;
}