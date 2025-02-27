#pragma once
#include <iostream>
#include <string>
#include "Item.h"
using namespace std;

class Room
{
private:
	string description = "";
public:
	void Description() const;

	Room();
	Room(string newDesc, Item* newItem);
	~Room();

	Item* item;

	void SetDescription(string);
	void UpdateDescription();
};