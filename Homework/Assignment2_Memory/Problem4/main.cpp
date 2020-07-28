#include <iostream>

using namespace std;

int* getData(int&);
int* sumAry(const int*, int);
void prntAry(const int*, int);

int main(){
    int size = 0;
	int* array = getData(size);
    prntAry(array, size);
    cout << endl;
    int* sums = sumAry(array, size);
    prntAry(sums, size);
	return 0;
}

int* getData(int& size){
    
    cin >> size;

    int* array = new int[size];
    
    for(int i=0;i<size;i++){
        cin >> array[i];
    }
    return array;
}

int* sumAry(const int* array, int size){
    
    int* sums = new int[size];
    
    for(int i=0;i<size;i++){
        if(i==0){
            sums[i] = array[i];
        }
        
        sums[i] = sums[i-1] + array[i];
    }
    return sums;
}

void prntAry(const int* array, int size){
    for(int i=0;i<size;i++){
        cout << array[i];
        if(i < size -1){ cout << " ";}
    }
}