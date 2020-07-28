/* 
 * File:   
 * Author: 
 * Created on 
 * Purpose:  
 */

//System Libraries
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

struct DivState {
    string name;
    float firstSal;
    float secSal;
    float thrdSal;
    float frthSale;
    float totalSale;
    float avgSale;
};

void GetDivStats(DivState &div){

    cout << div.name << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> div.firstSal;
    cout << "Enter second-quarter sales:" << endl;
    cin >> div.secSal;
    cout << "Enter third-quarter sales:" << endl;
    cin >> div.thrdSal;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> div.frthSale;
    div.totalSale = div.firstSal + div.secSal + div.thrdSal + div.frthSale;
    div.avgSale =div.totalSale /4;
    cout << "Total Annual sales:$" << fixed << setprecision(2) << div.totalSale  << endl;
    cout << "Average Quarterly Sales:$" << fixed << setprecision(2) << div.avgSale;
    //Total·Annual·sales:$4400.00↵
    //Average·Quarterly·Sales:$1100.00↵

}

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    // East, West, North, and South
    
    DivState northDiv;
    northDiv.name = "North";
    DivState westDiv;
    westDiv.name = "West";
    DivState southDiv;
    southDiv.name = "South";
    DivState eastDiv;
    eastDiv.name = "East";

    
    GetDivStats(northDiv); cout << endl;
    GetDivStats(westDiv); cout << endl;
    GetDivStats(eastDiv); cout << endl;
    GetDivStats(southDiv);
    
    
    return 0;
}