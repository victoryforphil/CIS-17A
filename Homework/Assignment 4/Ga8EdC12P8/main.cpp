
#include <string>
#include <iostream>
#include <fstream>
void arrayToFile(std::string path, int* array, int size){
    std::ofstream file (path, std::ios::out | std::ios::binary);
    file.write((char *)array,size * sizeof(int));
    file.close();
}
void fileToArray(std::string path, int* array, int size){
    std::ifstream file (path, std::ios::out | std::ios::binary);
    file.read((char *)array,size * sizeof(int));
    file.close();
}

int main(){
    const int ARRAY_SIZE = 20;
    int *array = new int[ARRAY_SIZE];

    for(int i=0;i<ARRAY_SIZE;i++){
        array[i] = i * 2;
    }

    arrayToFile("test.dat", array, ARRAY_SIZE);

    array = new int[ARRAY_SIZE]; // Clear Array

    fileToArray("test.dat", array, ARRAY_SIZE);

    for(int i=0;i<ARRAY_SIZE;i++){
        std::cout << array[i] << " ";
    }

    return 0;
}