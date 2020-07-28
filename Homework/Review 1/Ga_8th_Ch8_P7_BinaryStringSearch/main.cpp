/* 
 * Assignment: Review Homework 1
 * SubAssignemnt: 8.7
 * Author: Alex Carter
 * Created on 6/29/2020
 */

//Imports

#include <cstdlib>
#include<string>
#include <iostream>
#include <algorithm>
//Imported from book
int binarySearch(const std::string array[], int numElems, std::string value)
{
    std::cout << "Search for: " << value << std::endl;
    int first = 0,           // First array element
        last = numElems - 1, // Last array element
        middle,              // Midpoint of search
        position = -1;       // Position of search value
    bool found = false;      // Flag
    while (!found && first <= last)
    {
        middle = (first + last) / 2; // Calculate midpoint
        std::cout << "\tComparing:  " << array[middle]  << " vs " << value << std::endl;
        if (array[middle] == value)  // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > value) // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1; // If value is in upper half
    }
    return position;
}

int main()
{
    const int NUM_NAMES = 20;
    std::string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                               "Taylor, Terri", "Johnson, Jill",
                               "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                               "James, Jean", "Weaver, Jim", "Pore, Bob",
                               "Rutherford, Greg", "Javens, Renee",
                               "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth"};
    // Insert your code to complete this program
    std::sort(names,names+20);
    // Get an employee name to search for.
    std::string empName;
    std::cout << "Enter the employee name you wish to search for: ";
    std::getline(std::cin,empName,'\n');
    int results;
    // Search for the ID.
    results = binarySearch(names, NUM_NAMES, empName);

    // If results contains −1 the ID was not found.
    if (results == -1)
        std::cout << "That name does not exist in the array. \n";
    else
    {
        // Otherwise results contains the subscript of
        // the specified employee ID in the array.
        std::cout << "That name is found at element " << results;
        std::cout << " in the array.\n";
    }
    return 0;

}