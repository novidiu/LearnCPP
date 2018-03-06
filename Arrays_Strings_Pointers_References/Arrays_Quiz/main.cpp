/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ovidiu Nitescu
 *
 * Created on February 3, 2018, 1:42 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

namespace Animals
{
    enum Animals
    {
        CHICKEN,
        DOG,
        CAT,
        ELEPHANT,
        DUCK,
        SNAKE,
        MAX_ANIMALS
    };
}

int main(int argc, char** argv)
{
/*===============================QUIZ 1================================
 *   Declare an array to hold the high temperature (to the nearest
 * tenth of a degree) for each day of a year (assume 365 days in a year).
 * Initialize the array with a value of 0.0 for each day.
 */   
    
    double temperature[365] = { 0.0 };
    
/*==============================QUIZ 2===============================
 *   Set up an enum with the names of the following animals: chicken,
 * dog, cat, elephant, duck and snake. Put the enum in a namespace. 
 * Define an array with an element for each of these animals, and use 
 * an initializer list to initialize each element to hold the number 
 * of legs that animal has.
 *   Write an main function that prints the number of legs an elephant 
 * has using the enumerator.
 */    
    
    int number_of_legs[Animals::MAX_ANIMALS] = { 2, 4, 4, 4, 2, 0 };
    cout << "An elephant has " << number_of_legs[Animals::ELEPHANT] << " legs" << "\n";
    
    return 0;
}

