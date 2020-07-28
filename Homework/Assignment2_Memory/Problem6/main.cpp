#include <iostream>

using namespace std;

int* getData(int&);
int* augment(const int*, int);
void prntAry(const int*, int);

int main(){
    int size = 0;
	int* array = getData(size);
    prntAry(array, size);
    cout << endl;
    int* augd = augment(array, size);
    prntAry(augd, size + 1);
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

int* augment(const int* array, int size){
    
    int* augd = new int[size + 1];
    augd[0] = 0;
    for(int i=1;i<size + 1;i++){
        
        augd[i] = array[i -1];
    }
    return augd;
}

void prntAry(const int* array, int size){
    for(int i=0;i<size;i++){
        cout << array[i];
        if(i < size -1){ cout << " ";}
    }
}