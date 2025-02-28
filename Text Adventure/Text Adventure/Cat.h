#pragma once
#include "Item.h"

class Cat : public Item
{
private:
	bool purring = false;
public:
	Cat();
	~Cat();
	const void Description();
	void Use();
};



