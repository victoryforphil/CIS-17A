#include <iostream>
#include <iomanip>
using namespace std;

int* getData(int &);
void prntData(int *, int);
float *median(int *, int);
void prntMed(float *, int);

int* intArr;

int main(){
	int size;
	int* array = getData(size);
	prntData(array, size);
	float *fArray = median(array, size);
	prntMed(fArray, size + 2);
	//your code here
	return 0;
}


int* getData(int &size){
  
    cin >> size;
    

    int* array = new int[size];
    
    for(int i=0;i<size;i++){
        cin >> array[i];
    }
    return array;
}
void prntData(int *array, int size){
    for(int i=0;i<size;i++){
        cout << array[i];
        if(i < size -1){ cout << " ";}else{cout << endl;}
    }
}
float *median(int *array, int size){
    
    float* flotArr = new float[size + 2];
    
    flotArr[0] = size + 2;
    if(size % 2 == 0){
        float low = array[(size / 2) - 1];
     
       float high = array[(size / 2) ]; 
       flotArr[1] = (low + high) / 2;
         
        //
    }else{
       flotArr[1] = array[(size / 2)];
    }
    
    for(int i=0;i<size;i++){
        flotArr[i+2] = array[i];
    }
    
    
    return flotArr;
}
void prntMed(float *array, int size){
    
     for(int i=0;i<size;i++){
        if(i > 0){cout << fixed << setprecision(2);}
        cout << array[i];
        if(i < size -1){ cout << " ";}
    }
}
