/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
#include <algorithm>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void sort(char [],int);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    sizeDet=read(array);//Determine it's size

    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn){
        sort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

int read(char in[]){
    char input;
    int index = 0;
    do{
        input = ' ';
        cin >> input;
        if(input != ' '){
            in[index] = input;
        index++;
        }
        
    }while(input != ' ');
    return index ;
}

void sort(char in[], int size){
    int i, j, min;  
    for (i = 0; i < size-1; i++)  
    {  
        min = i;  
        for (j = i+1; j < size; j++){
            if (in[j] < in[min])  
                min = j;  
        }
        int temp = in[min];  
        in[min] = in[i];  
        in[i] = temp;  
    }  
}

void print(const char in[], int size){
    for(int i=0;i<size;i++){
        std::cout << in[i];
    }
    
    std::cout << std::endl;
}