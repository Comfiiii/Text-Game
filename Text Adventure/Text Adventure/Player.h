#pragma once
#include <iostream>
#include <string>
#include <list>

class Player
{
private:
	
	std::string spells[10] =
	{
	{"Eclipse"},
	{"Eruption"},
	{"Frostbite"},
	{"Levitate"},
	{"Mirage"},
	{"Petrify"},
	{"Polymorph"},
	{"Teleport"},
	{"Thunderwave"},
	{"Vortex"},
	};

public:

	Player();
	~Player();
	bool FindSpell(std::string spell);

};