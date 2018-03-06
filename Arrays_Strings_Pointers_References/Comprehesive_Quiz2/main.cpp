/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ovidiu Nitescu
 *
 * Created on February 26, 2018, 10:45 AM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <random>

using namespace std;

struct Student
{
    string name;
    int grade;
};


void sortGrades(Student *students, int numStudent)
{
    for(int startIndex = 0; startIndex < numStudent; ++startIndex)
    {
        int maxIndex = startIndex;
        for (int currentIndex = startIndex + 1; currentIndex < numStudent; ++currentIndex)
        {
            if (students[currentIndex].grade > students[maxIndex].grade)
                maxIndex = currentIndex;
        }    
        swap(students[startIndex], students[maxIndex]);
    }
}

/*   Write the following program: Create a struct that holds a student's 
 * name and grade (on a scale of 0-100). Ask the user how many students they
 * want to enter. Dynamically allocate an array to hold all the students. 
 * Then prompt the user for each name and grade. Once the user has entered 
 * all the names and grades, short the list by grade (highest first). Then
 * print all the names and grades in sorted order.
 * 
 */
int main(int argc, char** argv) 
{
    int numStudent = 0;
    do
    {
        cout << "How many students do you want to enter? ";
        cin >> numStudent;
    }while (numStudent <= 1);
    
    Student *students = new Student[numStudent];
    
    for (int index = 0; index < numStudent; ++index)
    {
        cout << "Enter name#" << index + 1 << ": ";
        cin >> students[index].name;
        cout << "Enter " << students[index].name << "'s grade: ";
        cin >> students[index].grade;
    }
    
    sortGrades(students, numStudent);
    
    for(int index = 0; index < numStudent; ++index)
        cout << students[index].name << " got a grade of " << students[index].grade << "\n";
    
    delete[] students;
    return 0;
}

