#pragma once
#include <iostream>
using namespace std;

class Player
{
public:
	//cosntructor and function declarations in public
	Player();
	Player(char* name, int strength, int intelligence, int dexterity);
	//~Player();
	void printPlayer();
	char* getName();
	virtual void attack(Player* player);
	char* playerName;
private:
	//variable declarations in private
	int Strength;
	int Intelligence;
	int Dexterity;
};

