#include <iostream>

using namespace std;

int **getData(int&, int&);
void prntDat(const int* const *, int, int);
void destroy(int **, int, int);
int sum(const int* const*, int, int);
int main(){
    int sizeX, sizeY;
    int** array = getData(sizeX, sizeY);
    prntDat(array, sizeX, sizeY);
    cout << sum(array, sizeX, sizeY);
    destroy(array, sizeX, sizeY);
	return 0;
}

int **getData(int& sizeX, int& sizeY){
    cin >> sizeX;
    cin >> sizeY;
    
    int** array = new int*[sizeX];
    for(int x=0;x<sizeX;x++){
        array[x] = new int[sizeY];
        for(int y=0;y<sizeY;y++){
            cin >> array[x][y];
        }
    }
    return array;
}
void prntDat(const int* const * array, int sizeX, int sizeY){
    for(int x=0;x<sizeX;x++){
        
        for(int y=0;y<sizeY;y++){
            cout << array[x][y];
            if(y< sizeY -1){
                cout << " ";
            }
        }
        cout << endl;
    }
}
void destroy(int ** array, int sizeX, int sizeY){
    for(int x=0;x<sizeX;x++){
        delete[] array[x];
    }
    delete[] array;
}
int sum(const int* const* array, int sizeX, int sizeY){
    int mSum;
    for(int x=0;x<sizeX;x++){
        for(int y=0;y<sizeY;y++){
           mSum += array[x][y];
        }
    }
    return mSum;
}