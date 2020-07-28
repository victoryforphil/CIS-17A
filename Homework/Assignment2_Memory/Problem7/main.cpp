#include <iostream>

using namespace std;

int **getData(int&, int&);
void prntDat(const int* const *, int, int);
void destroy(int **, int, int);
int** augment(const int* const*, int, int);
int main(){
    int sizeX, sizeY;
    int** array = getData(sizeX, sizeY);
    prntDat(array, sizeX, sizeY);
    cout <<endl;
    int** augd = augment(array, sizeX, sizeY);
    prntDat(augd, sizeX + 1, sizeY + 1);
    destroy(array, sizeX, sizeY);
    destroy(augd, sizeX + 1, sizeY + 1);
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
        if(x < sizeX -1){
            cout << endl;
        }
    }
}
void destroy(int ** array, int sizeX, int sizeY){
    for(int x=0;x<sizeX;x++){
        delete[] array[x];
    }
    delete[] array;
}
int** augment(const int* const* array, int sizeX, int sizeY){
    int** augArr = new int*[sizeX + 1];
    
    for(int x=0;x<sizeX + 1;x++){
        
        augArr[x] = new int[sizeY + 1];
        for(int y=0;y<sizeY + 1;y++){
            if(x == 0 || y==0){
                augArr[x][y] = 0;
            }else{
                augArr[x][y] = array[x-1][y-1];
            }
        }
    }
    
    return augArr;
}