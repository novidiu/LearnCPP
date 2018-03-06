/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ovidiu Nitescu
 *
 * Created on January 29, 2018, 4:36 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

enum Animals
{
    ANIMAL_CAT = 3
};

/*
 * 
 */
int main(int argc, char** argv) 
{  
    int prime[5];    // hold the first 5 prime numbers
    prime[0] = 2;    // The first element has index 0
    prime[1] = 3;
    prime[2] = 5;
    prime[3] = 7;
    prime[4] = 11;   //The last element has index 4 (array length-1)
    
    cout << "The lowest prime number is: " << prime[0] << endl;
    int sum=0;
    for(int i=0; i<=4; i++)
        sum=sum+prime[i];
    cout << "The sum of the first 5 primes is: " << sum << endl;
    
    
    double array[4];   //allocate 3 doubles
    array[0]= 2.0;
    array[1]= 3.0;
    array[2]= 4.0;
    array[ANIMAL_CAT]= 5.0;
    
    cout << "The avarage of the array is: " << (array[0] + array[1] + array[2] + array[ANIMAL_CAT])/4 << endl;
    
#define ARRAY_LENGTH 5
    
    double array1[ARRAY_LENGTH];     //OK DECLARATION    
    
    return 0;
    
}

