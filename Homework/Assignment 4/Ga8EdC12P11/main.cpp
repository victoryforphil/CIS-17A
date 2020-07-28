
#include <string>
#include <iostream>
#include <fstream>

struct Division{
    std::string name;

    int sales[4];
};

Division getData(std::string name){
    Division div;
    div.name = name;
    std::cout << name << ": ";
    for(int i=0;i<4;i++){

        std::cout << "Enter Earning for Quarter: " << i + 1 << std::endl;
        std::cin >> div.sales[i];
        //div.sales[i] = (i+1) * 100;
    }
    return div;
}
void saveDivisions(std::string path, Division divs[4]){
    std::ofstream file(path,std::ios::out | std::ios::binary);
    file.write((char *)divs,sizeof(Division) * 4);
    file.close();
}
void readDivision(std::string path, Division *divs){
    std::ifstream file(path,std::ios::out | std::ios::binary);
    file.read((char *)divs,sizeof(Division) * 4);
    file.close();
}
int main(){
    Division divs[4];
    divs[0] = getData("North Division");
    divs[1] = getData("East Division");
    divs[2] = getData("West Division");
    divs[3] = getData("South Division");

    saveDivisions("data.dat",divs);
    Division readDiv[4];
    readDivision("data.dat", readDiv);
    for(int i=0;i<4;i++){
        std::cout << readDiv[i].name << std::endl;
        std::cout << " - " << 1 << " = " << readDiv[i].sales[0] << std::endl;
        std::cout << " - " << 2 << " = " << readDiv[i].sales[1] << std::endl;
        std::cout << " - " << 3 << " = " << readDiv[i].sales[2] << std::endl;
        std::cout << " - " << 4 << " = " << readDiv[i].sales[3] << std::endl;
         
    }
    return 0;
}