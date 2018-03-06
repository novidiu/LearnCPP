/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ovidiu Nitescu
 *
 * Created on February 17, 2018, 12:02 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstddef>

using namespace std;

namespace foo
{
    void doSomething(int *ptr)
    {
        if(ptr)
            cout << "You passed in " << *ptr << endl;
        else
            cout << "You passed in a null pointer" << endl;
    }
}

namespace coo
{
    void doSomething(nullptr_t prt)
    {
        cout << "in coo::doSomething()\n";
    }
}

/*
 * 
 */
int main(int argc, char** argv) 
{
    int *ptr { 0 }; //ptr is now a null pointer
    
    int *ptr2;      //ptr2 is uninitialized
    ptr2 = 0;       //ptr2 is now a null pointer
    
    if (ptr)
        cout << "ptr is pointing to an integer value." << endl;
    else
        cout << "ptr is a null pointer." << endl;
    
    foo::doSomething(nullptr);
    coo::doSomething(nullptr);
    int x = 4;
    int *xPtr = &x;
    nullptr_t null;
    coo::doSomething(null);

    foo::doSomething(xPtr);

    return 0;
}

