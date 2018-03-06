/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ovidiu Nitescu
 *
 * Created on February 19, 2018, 11:15 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

namespace Foo
{
    void printSize (int array[])
    {
       cout << sizeof (array) << endl; 
    }
}

namespace Voo
{
    void printSize (int *array)
    {
        cout << sizeof(array) << endl;
    }
}

void changeArray(int *ptr)
{
    *ptr = 5;
}

/*
 * 
 */
int main(int argc, char** argv) 
{
    int array[5] = { 9, 7, 5, 3, 1 };
    const int arraylength = sizeof(array) / sizeof(array[0]);
    
    cout << "The array has address: " << array << endl;
    for(int index = 0; index < arraylength; ++index)
    cout << "Element " << index <<  " has address: " << &array[index] << endl;
    
    
    char name[] = "Ovidiu";
    cout << *name << endl;
    
    int *ptr = array;
    cout << *array << endl;
    cout << *ptr << endl;
    cout << sizeof(array) << endl;
    cout << sizeof(ptr)   << endl;
    
    
    int anotherarray[] = { 1, 2, 1, 4, 5, 6, 7, 8 };
    cout << sizeof(anotherarray) << endl;
    Foo::printSize(anotherarray);
    Voo::printSize(anotherarray);
    
    cout << "Element 0 has value: " << anotherarray[0] << endl;
    changeArray(anotherarray);
    cout << "After changeArray, element 0 has value: " << anotherarray[0] << endl;
    
    return 0;
}

