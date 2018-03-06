/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ovidiu Nitescu
 *
 * Created on February 6, 2018, 11:01 AM
 */

#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

int readValue()
{
    int value;
    do
    {
        cout << "Enter a number between 1 and 9: ";
        cin >> value;
        
        if (cin.fail())
            cin.clear();
        
        cin.ignore(32767, '\n');
    }while ( value < 1 || value > 9);
    
    return value;
}

/*
 * 
 */
int main(int argc, char** argv)
{
    int scores[] = { 84, 92, 76, 81, 56 };
    const int numberStudents =sizeof(scores) / sizeof(scores[0]);
    int totalScore = 0;
    int maxScore = 0;
    
    for (int student=0; student < numberStudents; ++student)
        totalScore += scores[student];
    
    cout << "The total score is: " << totalScore << endl;
    
    
    for (int student = 0; student < numberStudents; ++student)
        if (scores[student] > maxScore)
            maxScore = scores[student];
    
    cout << "The best score was: " << maxScore << endl;

    /*===========================QUIZ 1===========================
     *   Print the following array to the screen using a loop:
     *   array[] = { 4, 6, 7, 3, 2, 1, 9, 5 } 
     */
    
    int array[] = { 4, 6, 7, 3, 2, 1, 9, 5, 8 };
    int arrayLength = sizeof(array) / sizeof(array[0]);
    
    cout << "array[] = { ";
    for (int iterator = 0; iterator < arrayLength; ++iterator)
        cout << array[iterator] << " " ;
    cout << "}" << endl;
    
    
    /*============================QUIZ 2============================
     *   Given the array in question 1:
     *   Ask the user for a number between 1 and 9. If the user does 
     * not enter a number between 1 and 9, repeatedly ask for an 
     * integer until they do. Once they have entered a number between
     * 1 and 9, print the array. Then search the array for the value
     * that the user entered and print the index of that element.
     */
    
    int number;
    number = readValue();   //read in valid input from user
    
    //Print the array
    
    for (int index = 0; index < arrayLength; ++index)
        cout << array[index] << " ";
    
    cout << endl;
    
    // Search the array to find the matching number and print the index
    for (int index = 0; index < arrayLength; ++index)
    {
        if (array[index] == number)
        {
            cout << "The number " << number << " has index " << index << endl;
            break;
        }
    }
    
    /*============================QUIZ 3=========================
     * Find and print the maximum value of the array and also the
     * the index of this value. 
     */
    int maxValue=0;
    int maxIndex=0;
    
    for (int index = 0; index < arrayLength; ++index)
    {
        if(array[index] > maxValue)
        {
            maxValue = array[index];
            maxIndex = index;
        }
    }
    
    cout << "The maximum value of array[] is " << maxValue << " and has index " << maxIndex << endl;
    return 0;
}

