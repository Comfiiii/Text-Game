#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Player
{
private:
	list <string> spells;
public:

	Player();
	~Player();
	bool FindSpell(string spell);

};