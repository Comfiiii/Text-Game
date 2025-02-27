#pragma once
#include <iostream>
#include <string>
#include "Item.h"
using namespace std;

class Room
{
private:
	string roomdescription = "";
public:
	void RoomDesc() const;

	Room();
	Room(string newDesc, Item* newItem);
	~Room();

	Item* item;

	void UpdateDescription();
};