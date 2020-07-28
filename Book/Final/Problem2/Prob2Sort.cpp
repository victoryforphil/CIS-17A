/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob2Sort.cpp
 * Author: Victo
 * 
 * Created on July 27, 2020, 10:03 PM
 */

#include "Prob2Sort.hpp"



template<class T>
T* Prob2Sort<T>::sortArray(const T *input, int len, bool ascend){
    return input;
}
template<class T>
T *Prob2Sort<T>::sortArray(const T *input, int lenX, int lenY, int col, bool ascend){

    T* colArr = new T[lenY]; // Y axis = cols

    for(int i=0;i<lenX;i++){
        colArr[i] = input[(lenY * i) + col];
    }

    return input;
}