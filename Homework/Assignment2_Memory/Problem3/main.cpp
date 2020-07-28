#include <iostream>

using namespace std;

int* getData(int&);
int* sort(const int*, int);
int* reverse(const int*, int);
void prntAry(const int*, int);

int main(){
    int size = 0;
	int* array = getData(size);
   
   
    int* sorted = sort(array, size);
     prntAry(sorted, size);
      cout << endl;
    int* rev = reverse(sorted, size);
    prntAry(rev, size);
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

int* sort(const int* array, int size){
    int* sorted = new int[size];
    memcpy(sorted, array, size * sizeof(int));
    int i, key, j;  
    for (i = 1; i < size; i++) 
    {  
        key = sorted[i];  
        
        j = i - 1;  
        while (j >= 0 && sorted[j] > key) 
        {  
            sorted[j + 1] = sorted[j];  
            j = j - 1;  
        }  
        sorted[j + 1] = key;  
    }  
    return sorted;
}

int* reverse(const int* array, int size){
    int* rv = new int[size];
    
    for(int i=0;i<size;i++){
        rv[i] = array[size-1-i];
    }
    return rv;
}

void prntAry(const int* array, int size){
    for(int i=0;i<size;i++){
        cout << array[i];
        if(i < size -1){ cout << " ";}
    }
}