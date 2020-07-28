/* 
 * Assignment: Review Homework 1
 * SubAssignemnt: 7.6
 * Author: Alex Carter
 * Created on 6/29/2020
 */


/*
An amateur meteorologist wants to keep track of weather conditions during the
past year’s three-month summer season and has designated each day as either rainy
(‘R’), cloudy (‘C’), or sunny (‘S’). Write a program that stores this information in a
3 × 30 array of characters, where the row indicates the month (0 = June, 1 = July,
2 = August) and the column indicates the day of the month. Note that data are not
being collected for the 31st of any month. The program should begin by reading the
weather data in from a file. Then it should create a report that displays, for each
month and for the whole three-month period, how many days were rainy, how many
were cloudy, and how many were sunny. It should also report which of the three
months had the largest number of rainy days. Data for the program can be found in
the RainOrShine.txt file. 
*/

//Imports

// 1. Load the file
// 2. Split the loaded lines into arrays
// 3. Print Rainy dats (3 month and 1 month total)
// 4. Print Cloud dats (3 month and 1 month total)
// 5. Print Sunny dats (3 month and 1 month total)
// 6. Print max raniny

#include <cstdlib>
#include <iostream>
#include <fstream>

int main() {
    std::ifstream stream("RainOrShine.txt");
    std::string line; //parsing line
    int idx = 0; // Row Counter;

    char data[3][30];

    while (std::getline(stream, line)) {
      
        for(int i=0;i<30;i++){
            data[idx][i] = line[i];
            
        }
        idx++;
    }

    int rMonth[3] = {0,0,0};
    int sMonth[3] = {0,0,0};
    int cMonth[3] = {0,0,0};

    int rTotal, sTotal, cTotal;

    int rMax, rMaxId;

    for(int i=0;i<3;i++){

        for(int j=0;j<30;j++){
            std::cout << data[i][j] << " ";

            switch(data[i][j]){
                case 'R':
                rTotal++;
                rMonth[i]++;

                if(rMonth[i] > rMax){
                    rMax = rMonth[i];
                    rMaxId = i;
                }
                break;

                case 'S':
                sTotal++;
                sMonth[i]++;
                break;

                case 'C':
                cTotal++;
                cMonth[i]++;
                break;
            }
        }

        std::cout << std::endl;
    }
    std::string months[] = {"July", "June", "August"};
    for(int i=0;i<3;i++){
        std::cout << months[i] << " rain total: " << rMonth[i]<< std::endl;
        std::cout << months[i] << " sun total: " << sMonth[i]<< std::endl;
        std::cout << months[i] << " cloud total: " << cMonth[i]<< std::endl;
    }

    std::cout << "Sun Total: " << sTotal << std::endl;
    std::cout << "Cloud Total: " <<cTotal << std::endl;
    std::cout << "Rain Total: " << rTotal << std::endl;

    std::cout << "Biggest Rain Month: " << months[rMaxId] << std::endl;
    return 0;
}

