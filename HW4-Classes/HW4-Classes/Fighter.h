#pragma once
#include "Player.h"
#include <iostream>
using namespace std;

class Fighter :
    public Player
{
public:
    Fighter();
    Fighter(char* name, char* weaponSkill, int strength, int intelligence, int dexterity);
    //~Fighter();
    void printFighter();
    virtual void attack(Player* player);
private:
    char* WeaponSkill;
};

