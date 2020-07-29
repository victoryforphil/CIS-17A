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

template <class T>
class Prob2Sort
{
private:
	int *index; //Index that is utilized in the sort
public:
	Prob2Sort() { index = nullptr; };	//Constructor
	~Prob2Sort() { delete[] index; };	//Destructor

	T *sortArray(const T *path, int len, bool ascend){
    	return input;
	};

	T *sortArray(const T *path, int lenX, int lenY, int col, bool ascend)
	{

		int len = lenX * lenY;

		T* table = new T[len];

		std::ifstream file(path);
		std::string line;

		for (int i = 0; i < rowLen; i++)
		{
			T *colArr = new T[lenY]; // Y axis = cols

			for (int i = 0; i < lenX; i++)
			{
				colArr[i] = input[(lenY * i) + col];
			}
		}
		return input;
	}; //Sorts a 2 dimensional array represented as a 1 dim array
};

#endif /* PROB2SORT_HPP */
