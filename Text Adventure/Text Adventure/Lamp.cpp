#include "Item.h"
#include "Lamp.h"

Lamp::Lamp()
{

}

Lamp::~Lamp()
{

}

const void Lamp::Description()
{
	std::cout << "This is a Lamp\n";
}

void Lamp::Use()
{
	turnedOn = true;
	if (turnedOn == true)
	{
		std::cout << "-------------------------------------------------------\n";
		std::cout << "You turn on the lamp, it kinda burns your eyes a bit but oh well..\n";
	}
	else
	{
		std::cout << "The Lamp is not on :(\n";
	}
}