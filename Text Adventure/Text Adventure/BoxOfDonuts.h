#pragma once
#include "Item.h"

class BoxOfDonuts : public Item
{
private:
	unsigned int count = 4294967296;
public:
	BoxOfDonuts();
	~BoxOfDonuts();
	void Description() const override;
	void Use() override;
};



