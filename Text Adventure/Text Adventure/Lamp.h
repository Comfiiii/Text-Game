#pragma once
#include "Item.h"

class Lamp : public Item
{
private:
	bool turnedOn = false;
public:
	Lamp();
	~Lamp();
	void Description() const override;
	void Use() override;
};


