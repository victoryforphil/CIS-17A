/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob3Table.hpp
 * Author: Victo
 *
 * Created on July 28, 2020, 6:22 PM
 */

#ifndef PROB3TABLE_HPP
#define PROB3TABLE_HPP
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <iostream>
template <class T>
class Prob3Table
{
protected:
	int rows;	  //Number of rows in the table
	int cols;	  //Number of cols in the table
	T *rowSum;	  //RowSum array
	T *colSum;	  //ColSum array
	T *table;	  //Table array
	T grandTotal; //Grand total
	void calcTable(void)
	{
		rowSum = new T[rows];
		colSum = new T[cols];

		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < cols; cols++)
			{
				rowSum[row] += table[row + col];
				colSum[col] += table[row + col];
			}
		}
	}; //Calculate all the sums
public:
	Prob3Table(char *path, int rowLen, int colLen)
	{

		rows = rowLen;
		cols = colLen;
		table = new T[rowLen * colLen];
		std::ifstream file(path);
		std::string line;
		for (int i = 0; i < rowLen; i++)
		{
			
			/*
			std::getline(file, line);
			int colIdx = 0;
			for (int j = 0; j < strlen(line.c_str()); j++)
			{
				char valueStr[3];
				int idx;
				if (line.c_str()[j] != ' ' && idx < 3)
				{
					valueStr[idx] = line.c_str()[j];
					idx++;
				}
				else
				{
					std::cout << "Value Ready for parsing: " << valueStr << std::endl;
					idx = 0;
					table[(i * colIdx) + colIdx] = (i * colIdx) + colIdx;
					colIdx++;
				}
			}
			*/
			for(int j=0;j<colLen;j++){
				table[(i*colLen) + j] = (i*colLen) + j;
			}

			
			// std::memcpy(table, data, rowLen * colLen);
		}
		file.close();
	}; //Constructor then Destructor
	~Prob3Table()
	{
		delete[] table;
		delete[] rowSum;
		delete[] colSum;
	};
	const T *getTable(void) { return table; };
	const T *getRowSum(void) { return rowSum; };
	const T *getColSum(void) { return colSum; };
	T getGrandTotal(void) { return grandTotal; };
};

#endif /* PROB3TABLE_HPP */
