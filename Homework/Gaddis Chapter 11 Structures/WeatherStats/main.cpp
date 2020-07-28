#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Weather{
  string month;
  float rain;
  int highTemp;
  int lowTemp;
  int avgTemp;
};

void getData(Weather &toFill){
    cin >> toFill.month;
    cin >> toFill.rain;
    cin >> toFill.lowTemp;
    cin >> toFill.highTemp;

}

int main(){
    int lowIdx = 0;
    int highIdx = 0;
    float avgTemp = 0;
    float avgRain = 0;
    Weather* weathDat = new Weather[12];
	for(int i=0;i<12;i++){
	    getData(weathDat[i]);
	        
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
	
	avgTemp /= 12.0;
	avgRain /= 12.0;

    cout << "Average Rainfall " << fixed << setprecision(1) << avgRain << " inches/month"<<endl;
    cout << "Lowest  Temperature " << weathDat[lowIdx].month << "  "<<weathDat[lowIdx].lowTemp<<" Degrees Fahrenheit" << endl;
	cout << "Highest Temperature " << weathDat[highIdx].month << "  "<<weathDat[highIdx].highTemp<<" Degrees Fahrenheit" << endl;
	cout << "Average Temperature for the year "<< fixed << setprecision(0) << avgTemp << " Degrees Fahrenheit" << endl;
	return 0;
}