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
#include <cstring>
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
			rowSum[row] = 0;
		}
		for (int col = 0; col < cols; col++)
		{
			colSum[col] = 0;
		}

		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < cols; col++)
			{
				int idx = ((rows + 1) * row) + col;
				//std::cout << "Row #" << row << " adding" << table[row + col] << std::endl;
				rowSum[row] += table[idx];
				colSum[col] += table[idx];
			}
		}
	}; //Calculate all the sums
public:
	/*
	std::stringstream str(num); 
					T type;
					str >> type;
					table[(i * rowLen) + colIdx] = type;
					colIdx++;
					*/
	Prob3Table(char *path, int rowLen, int colLen)
	{

		rows = rowLen;
		cols = colLen;
		table = new T[rowLen * colLen];
		std::ifstream file(path);

		for (int i = 0; i < rowLen; i++)
		{
			std::string line;
			std::getline(file, line);
			int len = std::strlen(line.c_str());
			//std::cout << "Line: " << line << std::endl;
			int cnt = 0;
			int col = 0;
			char buf[3];
			for (int j = 0; j < len; j++)
			{
				char cur = line.c_str()[j];
				//std::cout << "Count: " << cnt << ", Cur: " << cur << std::endl;
				if (cur == ' ' || cur == '\n')
				{

					std::stringstream str(buf);
					T type;
					str >> type;

					int idx = ((rowLen + 1) * i) + col;
					table[idx] = type;

					col++;
					cnt = 0;
				}
				else
				{
					buf[cnt] = cur;
					cnt++;
				}
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
