/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ovidiu Nitescu
 *
 * Created on February 19, 2018, 12:04 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

char askUserName()
{
    cout << "Dear user please enter your name: ";
    char name;
    cin >> name;
    return name;
}

/*
 * 
 */
int main(int argc, char** argv) 
{
    int array[] = { 9, 7, 5, 3, 1 };
    const int arraylength = sizeof(array) / sizeof(array[0]);
    
    for (int index = 0; index < arraylength; ++index)
        cout << "Element " << index << "is at address: " << &array[index] << endl;
    
    cout << &array[1] << endl; // print memory address of array element 1
    cout << array+1 << endl;   // print memory address of pointer + 1
    
    int index = 0;
    while (index < arraylength)
    {
        cout << "Memory address " << array+index << " hold the value " << *(array+index);
        cout << endl;
        ++index;
    }
    
    //char userName = askUserName();
    //cout << userName;
    
    const int wordLength = 7;
    char word[wordLength] = "Mollie";
    int numberVowels(0);
    
    for (char *ptr = word; ptr < word + wordLength; ++ptr)
    {
        switch(*ptr)
        {
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'i':
            case 'O':
            case 'o':
            case 'U':
            case 'u':
                ++numberVowels;
        }
    }
    
    cout << word << " has " << numberVowels << " vowels. \n";
    return 0;
}

