#include "Player.h"
#include <iostream>
using namespace std;

//default constructor
Player::Player()
{
	playerName = (char*)"Unknown";
	Strength = 10;
	Intelligence = 10;
	Dexterity = 10;
}

//parameterized constructor
Player::Player(char* name, int strength, int intelligence, int dexterity)
{
	playerName = name;
	Strength = strength;
	Intelligence = intelligence;
	Dexterity = dexterity;
}

//function to print out player stats and info
void Player::printPlayer()
{
	cout << playerName << "\n";
	cout << "Your strength is: " << Strength << "\n";
	cout << "Your intelligence is: " << Intelligence << "\n";
	cout << "Your dexterity is: " << Dexterity << "\n";
}

//destructor
/*
Player::~Player()
{
	delete playerName;
	cout << "Destroying player object";
}
*/

char* Player::getName()
{
	return playerName;
}

void Player::attack(Player* player)
{
	cout << playerName << " attacks " << player->getName() << "!";
}