#pragma once
#include <iostream>
#include <string>
#include "Item.h"

class Room
{
private:
	std::string description = "";
public:
	void Description() const;

	Room();
	Room(std::string newDesc, Item* newItem);
	~Room();

	Item* item;

	void SetDescription(std::string);
	void UpdateDescription();
};