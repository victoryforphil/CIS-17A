#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


struct Drink{
    string name;
    int cost;
    int num;
};
void displayDrinks(Drink drinks[], int size){
    for(int i=0;i<size;i++){
        cout << left<< setfill(' ') << setw(11) << drinks[i].name << setw(4) << drinks[i].cost<< drinks[i].num<< endl;
    }
}
int main(){
	Drink drinks[5];
	drinks[0].name = "Cola";
	drinks[0].cost = 75;
	drinks[0].num  = 20;
	
	drinks[1].name = "Root Beer";
	drinks[1].cost = 75;
	drinks[1].num  = 20;
	
	drinks[2].name = "Lemon-Lime";
	drinks[2].cost = 75;
	drinks[2].num  = 20;
	
	drinks[3].name = "Grape Soda";
	drinks[3].cost = 80;
	drinks[3].num  = 20;
	
	drinks[4].name = "Cream Soda";
	drinks[4].cost = 80;
	drinks[4].num  = 20;
	
	bool quit= false;
	int timeout = 0;
	int total= 0 ;
	while(!quit && timeout < 10){
	    displayDrinks(drinks, 5);
	    cout << "Quit" << endl;
	    
	    string choice = "";
	    getline(cin, choice);
	    
	    
	    int choiceIdx = 0;
	    
	    if(choice == "Cola"){choiceIdx = 0;}
	    else if(choice == "Root Beer"){choiceIdx = 1;}
	    else if(choice == "Lemon Lime"){choiceIdx = 2;}
	    else if(choice == "Grape Soda"){choiceIdx = 3;}
	    else if(choice == "Cream Soda"){choiceIdx = 4;}
	    else if(choice == "Quit"){quit == true; break;}
	    if(drinks[choiceIdx].num <=0){
	        cout << "Sold out!" << endl;
	        
	    }else{
	        int payment = 0;
	        do{
	            getline(cin, choice);
	            payment = stoi(choice.c_str());
	        }while(payment <=0 || payment >= 100);
	    
	        cout << payment - drinks[choiceIdx].cost << endl;
	        drinks[choiceIdx].num--;
	        timeout++;
	    
	        total +=drinks[choiceIdx].cost ;
	    }
	    
	}
	
	cout << total << endl;
	return 0;
}