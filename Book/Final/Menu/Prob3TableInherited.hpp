/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob3TableInherited.hpp
 * Author: Victo
 *
 * Created on July 28, 2020, 6:22 PM
 */
#include "Prob3Table.hpp"
#ifndef PROB3TABLEINHERITED_HPP
#define PROB3TABLEINHERITED_HPP

template<class T>
class Prob3TableInherited: public Prob3Table<T>
{
	protected:
		T *augTable;                                  //Augmented Table with sums
	public:
		Prob3TableInherited(char * path,int row ,int col) 
		: Prob3Table<T>(path, row, col){

			this->calcTable();

			augTable = new T[(row+1) * (col+1)];
			int tmpIdx=0;
			T total = 0;
			for(int i=0;i<(row+1);i++){
				for(int j=0;j<(col+1);j++){
					int idx = ((row + 2) * i) + j;
					
					if(i < row && j < col){
						augTable[idx] = this->getTable()[tmpIdx];
						total += this->getTable()[tmpIdx];
						//std::cout << total << std::endl;
						tmpIdx++;
					}else if(j<col){
						augTable[idx] = this->getColSum()[j];
						
					}else if(i<row){
						augTable[idx] = this->getRowSum()[i];
						
					}else{
						
					}
					augTable[(row+1) * (col+1) - 1] = total;
				}
				
			}
		};          //Constructor
		~Prob3TableInherited(){delete [] augTable;};  //Destructor
		const T *getAugTable(void){return augTable;}; 
};

#endif /* PROB3TABLEINHERITED_HPP */

