/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ovidiu Nitescu
 *
 * Created on February 26, 2018, 10:29 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

enum ItemTypes
{
    ITEM_HEALTH_POTION,
    ITEM_TORCH,
    ITEM_ARROW,
    MAX_ITEMS
};

int countTotalItems(int *items)
{
    int totalItems = 0;
    for (int index = 0; index < MAX_ITEMS; ++index)
        totalItems += items[index];
    
    return totalItems;
}

/*   Pretend you're writing a game where the player can hold 3 types of items:
 * health potions, torches, and arrows. Create an enum to identify the 
 * different types of items, and a fixed array to store the number of 
 * each item the player is carrying (use built-in fixed arrays). The player
 * should start with 2 health potions, 5 torches, and 10 arrows. Write a 
 * function called countTotalItems() that returns how many items the player
 * has in total. Have your main() function print the output of countTotalItems() 
 */
int main(int argc, char** argv) 
{
    int items[MAX_ITEMS]{ 2, 5, 10 };
    
    cout << "The player has " << countTotalItems(items) << " items in total.";

    return 0;
}

