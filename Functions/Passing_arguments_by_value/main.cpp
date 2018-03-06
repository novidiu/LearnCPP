/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ovidiu Nitescu
 *
 * Created on February 28, 2018, 8:10 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

void foo(int y)
{
    cout << "y = " << y << '\n';
    y = 6;
    cout << "y = " << y << '\n';
}

/*==================PROS AND CONS OF PASS BY VALUE===============
 * 
 */

int main(int argc, char** argv) 
{
    int x = 5;
    cout << "x = " << x << '\n';
    
    foo(x); 
    
    cout << "x = " << x << '\n';

    return 0;
}

