#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Movie{
    string title, director;
    string year, runTime;
};

void getData(Movie &toFill){

    getline(cin, toFill.title);
    getline(cin, toFill.director);
     getline(cin, toFill.year);
     getline(cin, toFill.runTime);

}
void printMovie(Movie movie){
    /*
    Title:·····The·coming·wave↵
    Director:··Wolfgang·Gentry↵
    Year:······1993↵
    Length:····52↵
    */
    cout << endl;
    cout <<left<<setfill(' ')<<setw(11)<< "Title: " << movie.title << endl;
    cout <<left<<setfill(' ')<<setw(11)<< "Director:" << movie.director << endl;
    cout << left<<setfill(' ')<<setw(11)<<"Year:" << movie.year << endl;
    cout << left<<setfill(' ')<<setw(11)<<"Length:" << movie.runTime << endl;
    
}
int main(){
    
    cout << "This program reviews structures" << endl;
    cout << "Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)."<<endl;
    
    
    int count = 0;
    string countStr;
    getline(cin, countStr);
    count = stoi(countStr);
    
    Movie movies[count];
    for(int i=0;i<count;i++){
        getData(movies[i]);
    }
    for(int i=0;i<count;i++){
        printMovie(movies[i]);
    }
    
	//your code here
	return 0;
}