/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ovidiu Nitescu
 *
 * Created on February 26, 2018, 9:41 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void sortArray(string *array, int length)
{
    for (int startIndex = 0; startIndex < length; ++startIndex)
    {
        int smallestIndex = startIndex;
        
        for (int currentIndex = startIndex + 1; currentIndex < length; ++ currentIndex)
        {
            if (array[currentIndex] < array[smallestIndex])
                smallestIndex = currentIndex;
        }
        swap(array[startIndex], array[smallestIndex]);
    }
}

/*
 * 
 */
int main(int argc, char** argv) 
{
    cout << "How many names would you like to enter? ";
    int length;
    cin >> length;
    
    //Dynamically allocate an array to hold the names
    string *names = new string[length];
    
    //Ask user to enter all the names
    for (int i = 0; i < length; ++i)
    {
        cout << "Enter name #" << i + 1 << ": ";
        cin >> names[i];        
    }
    
    sortArray(names,length);
    
    cout << "\nHere is your sorted list: \n";
    for (int i = 0; i < length; ++i)
        cout << "Name #" << i + 1 << ": " << names[i] << endl;
    
    delete[] names;
    return 0;
}

