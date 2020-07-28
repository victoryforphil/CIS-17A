/*
Write a function named arrayToFile. The function should accept three arguments:
the name of a file, a pointer to an int array, and the size of the array. The function
should open the specified file in binary mode, write the contents of the array to the file,
and then close the file.
Write another function named fileToArray. This function should accept three arguments: the name of a file, a pointer to an int array, and the size of the array. The
function should open the specified file in binary mode, read its contents into the array,
and then close the file.
Write a complete program that demonstrates these functions by using the arrayToFile
function to write an array to a file, and then using the fileToArray function to read
the data from the same file. After the data are read from the file into the array, display
the array’s contents on the screen. 
*/
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