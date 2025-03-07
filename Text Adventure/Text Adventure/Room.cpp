#include "Room.h"

void Room::Description() const
{
	std::cout << description;
	if (item != nullptr)
	{
	item->Description();
	}
}

Room::Room()
{

}

Room::Room(std::string newDesc, Item* newItem)
{
	description = newDesc;
	item = newItem;
}

Room::~Room()
{

}

void Room::SetDescription(std::string desc)
{
	description = desc;
}

void Room::UpdateDescription()
{
	std::string EmptyRandomiser[4] =
	{
	{"-------------------------------------------------------\nThis room is empty..\nWhere would you like to go now?\n"},
	{"-------------------------------------------------------\nThe room is to dark to see anything..\nYou feel around but find nothing.\n"},
	{"-------------------------------------------------------\nYou walk into what appears to be an empty room..\n"},
	{"-------------------------------------------------------\nThe room appears to be empty..\n"},
	};

	description = EmptyRandomiser[rand()%4];
}
