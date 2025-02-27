#pragma once
#include "Item.h"

class Cat : public Item
{
private:
	bool turnedOn = false;
public:
	Cat();
	~Cat();
	const void Description();
	void Use();
};

Cat::Cat()
{

}

Cat::~Cat()
{

}

const void Cat::Description()
{

}

void Cat::Use()
{
	
}

