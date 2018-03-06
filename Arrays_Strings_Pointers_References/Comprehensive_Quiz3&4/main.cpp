/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ovidiu Nitescu
 *
 * Created on February 28, 2018, 10:20 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*  
 * Write your own function to swap the value of two integer variables.
 * Write a main() function to test it.
 */

void swap(int &a, int &b)
{
    //Temporarily save value of a
    int temp = a;
    //Put value of b in a 
    a = b;
    //Put previous value of a in b
    b = temp;
}

/*
 *   Write a function to print a C-style string character by character.
 * Use a pointer to step through each character of the string and print
 * that character. Stop when you hit a null terminator. Write a main 
 * function that test the function with the string literal "Hello, world!".
 * Use the ++ operator to advanced the pointer to the next character.
 */

void printCString(const char *str)
{
    while(*str != '\0')
    {
        cout << *str << " ";
        ++str;        
    }
}


int main(int argc, char** argv) 
{
    int a = 6;
    int b = 8;
    swap(a, b);
    
    if (a == 8 && b == 6)
        cout << "It works!";
    else
        cout << "It's broken!";
    cout << "\n";
    
    printCString("Hello world!");
    return 0;
}

