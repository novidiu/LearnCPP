/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ovidiu Nitescu
 *
 * Created on February 17, 2018, 11:10 AM
 */

#include <cstdlib>
#include <iostream>
#include <typeinfo>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    int x = 5;
    cout << x << '\n';    //print the value of variable x
    cout << &x << '\n';   //print the memory address of variable x 
    cout << *&x << '\n';  //print the value at the memory address of variable x
    //====================================================================
    int value = 5;
    int *ptr = &value;
    cout << &value << endl; //print the address of variable value
    cout << value << endl;  //print the content of variable value
    cout << ptr << endl;    //print the address that ptr is holding
    cout << *ptr << endl;   //get the value that ptr is pointing to
    //====================================================================
    double y(4.0);
    cout << &y << " " << typeid(&y).name() << " " << y << endl;
    //=========================THE SIZE OF POINTERS=======================
    char *chPtr;  //chars are 1 byte
    int *iPtr;    //ints are usually 4 bytes
    struct Something 
    {
        int nX, nY, nZ;
    };
    Something *somethingPtr; //Something is probably 12 bytes
    Something point = { 1, 2, 3 };
    
    cout << sizeof(chPtr) << " bytes" << endl;
    cout << sizeof(iPtr) << " bytes" << endl;
    cout << sizeof(point) << " bytes" << endl;
    cout << sizeof(somethingPtr) << " bytes" << endl;   
    
    return 0;
}

