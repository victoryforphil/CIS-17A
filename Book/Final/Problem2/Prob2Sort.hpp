/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob2Sort.hpp
 * Author: Victo
 *
 * Created on July 27, 2020, 10:03 PM
 */

#ifndef PROB2SORT_HPP
#define PROB2SORT_HPP
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
template <class T>
class Prob2Sort
{
private:
	int *index; //Index that is utilized in the sort
public:
	Prob2Sort() { index = nullptr; }; //Constructor
	~Prob2Sort() { delete[] index; }; //Destructor

	T *sortArray(const T *data, int len, bool ascend)
	{
		
		T *sorted = new T[len];
		std::memcpy(sorted, data, len);
		int i, j, min_idx;
		for (i = 0; i < len - 1; i++)
		{
			min_idx = i;
			for (j = i + 1; j < len; j++)
				if (sorted[j] < sorted[min_idx] && ascend){
					min_idx = j;
				}
					
				else if(sorted[j] > sorted[min_idx] && !ascend){
					min_idx = j;
				}
			

			T temp = sorted[min_idx];  
   			sorted[min_idx] = sorted[i];  
    		sorted[i] = temp;  
		}

		return sorted;
	};

	T *sortArray(const T *data, int lenY, int lenX, int col, bool ascend)
	{

		int len = (lenX) * (lenY);
		T *tmpData = new T[len];
		std::memcpy(tmpData, data, len);
		T *colArr = new T[lenY]; // Y axis = cols

		for (int i = 0; i < lenY; i++)
		{
			int idx = ((lenX + 1) * i) + col;
			//std::cout << "Row: " << i << " true index: " << idx << " = " << data[idx] << std::endl;
			colArr[i] = data[idx];
		}
		colArr = sortArray(colArr, lenY, ascend);
		for (int i = 0; i < lenY; i++)
		{
			int idx = ((lenX + 1) * i) + col;
			//std::cout << "Row: " << i << " true index: " << idx << " = " << data[idx] << std::endl;
			tmpData[idx] =colArr[i];
		}

		return tmpData;
	}; //Sorts a 2 dimensional array represented as a 1 dim array
};

#endif /* PROB2SORT_HPP */
