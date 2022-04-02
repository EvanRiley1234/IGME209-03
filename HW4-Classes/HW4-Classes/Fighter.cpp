#include "Fighter.h"
#include "Player.h"
#include <iostream>
using namespace std;

Fighter::Fighter() : Player()
{
	WeaponSkill = (char*)"None";
}

Fighter::Fighter(char* name, char* weaponSkill, int strength, int intelligence, int dexterity) : Player(name, strength, intelligence, dexterity)
{
	WeaponSkill = weaponSkill;
}

void Fighter::printFighter()
{
	printPlayer();
	cout << "Your weaponSkill is: " << WeaponSkill << "\n";
}

/*
Fighter::~Fighter()
{
	delete WeaponSkill;
	cout << "Destroying fighter object";
}
*/

void Fighter::attack(Player* player)
{
	cout << playerName << " attacks " << player->getName() << " with a " << WeaponSkill <<"!";
}