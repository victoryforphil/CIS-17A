#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

enum MonthEnum {JANUARY, FEBUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

struct Weather{
  MonthEnum month;
  float rain;
  float highTemp;
  float lowTemp;
  float avgTemp;
};

void getData(Weather &toFill){
    /*
    Enter·the·total·rainfall·for·the·month:↵
    Enter·the·high·temp:↵
    Enter·the·low·temp:↵
    */
    cout << "Enter the total rainfall for the month:" << endl;
    cin >> toFill.rain;
    cout << "Enter the high temp:" << endl;
    cin >> toFill.highTemp;
    cout << "Enter the low temp:" << endl;
    cin >> toFill.lowTemp;

}

int main(){
    
    int numMonth = 6;
    int lowIdx = 0;
    int highIdx = 0;
    float avgTemp = 0;
    float avgRain = 0;
    Weather* weathDat = new Weather[numMonth];
	for(int i=0;i<numMonth;i++){
	    getData(weathDat[i]);
	    weathDat[i].month = static_cast<MonthEnum>(i);
        weathDat[i].avgTemp = (weathDat[i].highTemp + weathDat[i].lowTemp) / 2;

	    if(weathDat[i].lowTemp < weathDat[lowIdx].lowTemp){
	        lowIdx = i;
	    }
	    
	    if(weathDat[i].highTemp > weathDat[highIdx].highTemp){
	        highIdx = i;
	    }
	    
	    avgTemp += weathDat[i].avgTemp;
	    avgRain += weathDat[i].rain;
	}
	
	avgTemp /=numMonth;
	avgRain /= numMonth;


    /*
    Average·monthly·rainfall:7.25↵
    High·Temp:100↵
    Low·Temp:37↵
    Average·Temp:70.5
    */
    
    cout << "Average monthly rainfall:" << fixed << setprecision(2) << avgRain <<endl;
    cout << "High Temp:" << fixed << setprecision(0) << weathDat[highIdx].highTemp << endl;
    cout << "Low Temp:"<< fixed << setprecision(0)  << weathDat[lowIdx].lowTemp << endl;
    cout << "Average Temp:" << fixed<< setprecision(1) << avgTemp;

	return 0;
}