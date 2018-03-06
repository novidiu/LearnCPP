/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ovidiu Nitescu
 *
 * Created on February 16, 2018, 2:11 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    //Declare a 10x10 array
    const int numRows = 10;
    const int numCols = 10;
    int product[numRows][numCols] = { 0 };
    //Calculate a multiplication table
    for (int row = 0; row < numRows; ++row)
        for (int col = 0; col < numCols; ++col)
            product[row][col] = row * col;
    //Print the table
    for (int row = 1; row < numRows; ++row)
    {
        for (int col = 1; col < numRows; ++col)
            cout << product[row][col]<< "\t";
        cout << endl;
    }
    
   
    return 0;
}

