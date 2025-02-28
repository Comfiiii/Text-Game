#pragma once
#include "Item.h"

class Lamp : public Item
{
private:
	bool turnedOn = false;
public:
	Lamp();
	~Lamp();
	const void Description();
	void Use();
};


