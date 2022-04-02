// HW4-Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Fighter.h"

int main()
{
    //part 1 main

    //default on the stack variable
    Player John = Player();
    //parameterized constructor on the stack
    Player Jack = Player((char*)"Jack", 16, 11, 14);
    //default on the heap (pointer)
    Player* Josh = new Player();
    //parameterized constructor on the heap (pointer)
    Player* Josiah = new Player((char*)"Josiah", 12, 14, 16);

    //print each of them out
    John.printPlayer();
    Jack.printPlayer();
    Josh->printPlayer();
    Josiah->printPlayer();

    //delete the pointer players
    delete Josh;
    delete Josiah;

    //part 2 main

    //creating 2 fighters
    Fighter Ryan = Fighter();
    Fighter Rick = Fighter((char*)"Rick", (char*)"One-Handed", 16, 12, 14);

    //printing out their info
    Ryan.printFighter();
    Rick.printFighter();

    //part 3 main
    Player* listOfPlayers[11];
    int decider;
    for (int i = 0; i < 10; i++)
    {
        decider = rand() % 1 + 0;
        if (decider == 0)
        {
            listOfPlayers[i] = new Player((char*)"Jack", 16, 11, 14);
        }
        else
        {
            listOfPlayers[i] = new Fighter((char*)"Rick", (char*)"One-Handed Sword", 16, 12, 14);
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (listOfPlayers[i] == nullptr)
        {
        }
        else if(i == 10)
        {
            listOfPlayers[i]->attack(listOfPlayers[1]);
        }
        else
        {
            listOfPlayers[i]->attack(listOfPlayers[i + 1]);
        }
    }
}

