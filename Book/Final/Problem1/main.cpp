/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Victo
 *
 * Created on July 27, 2020, 10:01 PM
 */

#include <cstdlib>
#include "Prob1Random.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char **argv)
{

    char n = 5;
    char rndseq[] = {18, 33, 56, 79, 126};
    int ntimes = 100000;
    Prob1Random a(n, rndseq);
    for (int i = 1; i <= ntimes; i++)
    {
        a.randFromSet();
    }
    int *x = a.getFreq();
    char *y = a.getSet();
    
    for (int i = 0; i < n; i++)
    {
        cout << int(y[i]) << " occured " << x[i] << " times" << endl;
    }
    cout << "The total number of random numbers is " << a.getNumRand() << endl;
    return 0;
}
