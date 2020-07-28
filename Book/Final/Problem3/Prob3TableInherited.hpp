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

			calcTable();

			

		};          //Constructor
		~Prob3TableInherited(){delete [] augTable;};  //Destructor
		const T *getAugTable(void){return augTable;}; 
};

#endif /* PROB3TABLEINHERITED_HPP */

