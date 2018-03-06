/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Ovidiu Nitescu
 *
 * Created on February 16, 2018, 12:15 PM
 */

#include <cstdlib>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

/*
 *
 */
int main(int argc, char** argv)
{
    //=========================Swap() FUNCTION===========================
    int x = 4;
    int y = 2;
    cout << "Before swap: x=" << x << " and y=" << y << endl;
    swap(x,y);
    cout << "After swap: x=" << x << " and y=" << y << endl;

    //=========================SELECTON SORT=============================
    int array[] = { 30, 50, 20, 40, 10 };
    const int arrayLength = sizeof(array) / sizeof(array[0]);


    for (int startIndex = 0; startIndex < arrayLength - 1; ++startIndex)
    {
        int smallestIndex = startIndex;

        for (int currentIndex = startIndex + 1; currentIndex < arrayLength; ++currentIndex)
        {
            if(array[currentIndex] < array[smallestIndex])
                smallestIndex = currentIndex;
        }
        swap(array[startIndex],array[smallestIndex]);
    }

    for (int index = 0; index < arrayLength ; ++index)
        cout << array[index] << " ";

    cout << endl;

    //=======================Sort() FUNCTION=============================
    sort(array, array+arrayLength);
    for (int index = 0; index < arrayLength ; ++index)
        cout << array[index] << " ";

    cout << endl;
    /*===============================QUIZ 1==============================
     * Rewrite the selection sort code above to sort in descending order
     * (largest number first).
     */

    int anotherArray[] = { 30, 60, 20, 50, 40, 10 };
    const int lenght = sizeof(anotherArray) / sizeof(anotherArray[0]);

    for (int startIndex = 0; startIndex < lenght - 1; ++startIndex)
    {
        int largestIndex = startIndex;
        for(int currentIndex = startIndex + 1; currentIndex < lenght; ++currentIndex)
        {
            if (anotherArray[largestIndex] < anotherArray[currentIndex])
                largestIndex = currentIndex;
        }
        swap(anotherArray[startIndex], anotherArray[largestIndex]);
    }

    for (int index=0; index < lenght; ++index)
        cout << anotherArray[index] << " ";
    cout << endl;


    /*==========================QUIZ 3 and 4==============================
     * Another simple sort is called "bubble sort". Bubble sort works by
     * comparing adjacent pairs of elements, and swapping them if the
     * criteria is met. Write code that bubble sort an arbitrary array.
     */

    int bubbles[] = { 6, 3, 14, 2, 9, 7, 1, 5, 4, 8, 10, 8 };
    const int bubblesLenght = sizeof(bubbles) / sizeof(bubbles[0]);

    for (int iteration=0; iteration < bubblesLenght - 1; ++iteration)
    {
        int endOfArrayIndex(bubblesLenght - iteration);
        bool swapped(false);
        for (int currentIndex = 0; currentIndex < endOfArrayIndex -1; ++currentIndex)
        {
            if (bubbles[currentIndex] > bubbles[currentIndex + 1])
            {
                swap(bubbles[currentIndex],bubbles[currentIndex + 1]);
                swapped = true;
            }
        }
        if(!swapped)
        {
            cout << "Early termination on iteration " << iteration + 1 << endl;
            break;
        }
    }

    for(int index = 0; index < bubblesLenght; ++index)
        cout << bubbles[index] << " ";
    return 0;
}

