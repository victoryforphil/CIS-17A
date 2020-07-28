
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