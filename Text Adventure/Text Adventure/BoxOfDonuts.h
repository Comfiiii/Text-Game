#pragma once
#include "Item.h"

class BoxOfDonuts : public Item
{
private:
	unsigned int count = 4294967296;
public:
	BoxOfDonuts();
	~BoxOfDonuts();
	const void Description();
	void Use();
};



