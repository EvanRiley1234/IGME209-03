// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

class MovableObject
{
public:
	int xPos;
	int yPos;
	void PrintPos()
	{
		cout << "X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl;
		delete[] name;
	}
};

class Monster : public MovableObject
{
public:
	int damage;
};

int main()
{
	//Monster *boss = new Monster();
	//Player *pOne = new Player();
	MovableObject *boss = new Monster();
	MovableObject *pOne = new Player();
	Monster *fakeMonster = (Monster*)pOne;

	// add code here
	//print out the addresses
	std::cout << &boss;
	std::cout << &pOne;
	std::cout << &fakeMonster;

	//set the value for the positions
	boss->xPos = 4;
	boss->yPos = 5;
	pOne->xPos = 6;
	pOne->yPos = 7;
	fakeMonster->xPos = 8;
	fakeMonster->xPos = 9;

	//print out positions
	printf("\n");
	boss->PrintPos();
	printf("\n");
	pOne->PrintPos();
	printf("\n");
	fakeMonster->PrintPos();


	delete boss;
	delete pOne;
	delete fakeMonster;

	_getch();
    return 0;
}

