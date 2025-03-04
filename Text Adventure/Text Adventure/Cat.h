#pragma once
#include "Item.h"

class Cat : public Item
{
private:
	bool purring = false;
public:
	Cat();
	~Cat();
	void Description() const override;
	void Use() override;
};



