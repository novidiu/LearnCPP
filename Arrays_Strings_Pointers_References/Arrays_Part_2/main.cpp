/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ovidiu Nitescu
 *
 * Created on January 30, 2018, 3:38 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

enum class StudentNames
{
    ANCA,         // 0
    OVIDIU,       // 1
    STEFAN,       // 2
    TAVI,         // 3
    MAX_STUDENTS  // 4
};

namespace StudentsName
{
    enum StudentsName
    {
        
        ANCA,         // 0
        OVIDIU,       // 1
        STEFAN,       // 2
        TAVI,         // 3
        MAX_STUDENTS  // 4  
    };
}


void passValue(int value)   // value is a copy of the argument
{
    value = 99;  // so changing it here won't change the value of the argument
}

void passArray(int array[3]) //"array" is the actual array
{
    array[0] = 5;   // so changing it here will change the original argument
    array[1] = 3;
    array[2] = 2;
}
/*
 * 
 */
int main(int argc, char** argv)
{
    int testScores[static_cast<int>(StudentNames::MAX_STUDENTS)];   //allocate 4 integers
    testScores[static_cast<int>(StudentNames::ANCA)] = 76 ;
    testScores[static_cast<int>(StudentNames::OVIDIU)] = 75 ;
    
    if (testScores[static_cast<int>(StudentNames::ANCA)] > testScores[static_cast<int>(StudentNames::OVIDIU)] )
        cout << "WoW" << endl;
    else
        cout << "..." << endl;
    //Doing this is somewhat of a pain.
    
    int testagain[StudentsName::MAX_STUDENTS];
    testagain[StudentsName::ANCA] = 76;
    testagain[StudentsName::OVIDIU] = 75;
    
    if (testagain[StudentsName::ANCA] > testagain[StudentsName::OVIDIU])
        cout << "WoW (again)" << endl;
    else
        cout << "... (again)" << endl;
    //Better to use a standard enum in a namespace.
    
                 //=====Passing arrays to functions=====//
    /*   Because copying large arrays can be very expensive, C++ does 
     * not copy an array when an array is passed into a function.
     * Instead, the actual array is passed. this has the side effect
     * of allowing functions to directly change the value of array
     * elements!!! This can be useful or dangerous. 
     */
    
    int value = 1;
    cout << "before passValue: " << value << "\n";
    passValue(value);
    cout << "after passValue: " << value << "\n";
    
    int prime[3] = { 2, 3, 5 };
    cout << "before passArray: ";
    for (int i=0; i< sizeof(prime) / sizeof(prime[0]); i++)
        cout << prime[i] << " " ;
    cout << endl << "after passArray: ";
    
    passArray(prime);
    for (int i=0; i< sizeof(prime) / sizeof(prime[0]); i++)
        cout << prime[i] << " " ;
    cout << "\n";
    
    return 0;
}

