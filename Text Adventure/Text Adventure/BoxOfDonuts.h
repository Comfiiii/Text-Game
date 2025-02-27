#pragma once
#include "Item.h"

class BoxOfDonuts : public Item
{
private:
	int count = 12;
public:
	BoxOfDonuts();
	~BoxOfDonuts();
	const void Description();
	void Use();
};

BoxOfDonuts::BoxOfDonuts()
{

}

BoxOfDonuts::~BoxOfDonuts()
{

}

const void BoxOfDonuts::Description()
{

}

void BoxOfDonuts::Use()
{

}

