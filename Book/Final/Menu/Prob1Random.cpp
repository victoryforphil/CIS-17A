/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob1Random.cpp
 * Author: Victo
 * 
 * Created on July 27, 2020, 10:02 PM
 */

#include "Prob1Random.hpp"

Prob1Random::Prob1Random(const char len, const char * data){
    set = new char[len];
    std::memcpy(set, data, len);
    nset = len;
    freq = new int[len];
    for(int i=0;i<len;i++){
        freq[i] = 0;
    }
    numRand = 0;
    
}
Prob1Random::~Prob1Random(void){
    //delete &set;
    //delete &freq;
}
char Prob1Random::randFromSet(void){
    int idx = rand() % nset;
    numRand++;
    freq[idx]++;
    return set[idx];
}
int *Prob1Random::getFreq(void) const{
    return freq;
}
char *Prob1Random::getSet(void) const{
    return set;
}
int Prob1Random::getNumRand(void) const{
    return numRand;
}