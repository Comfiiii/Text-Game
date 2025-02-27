#include "Room.h"

void Room::RoomDesc() const
{
	cout << roomdescription;
	if (item != nullptr)
	{
	item->ItemDesc();
	}
}

Room::Room()
{

}

Room::Room(string newDesc, Item* newItem)
{
	roomdescription = newDesc;
	item = newItem;
}

Room::~Room()
{

}

void Room::UpdateDescription()
{
	string EmptyRandomiser[4] =
	{
	{"-------------------------------------------------------\nThis room is empty..\nWhere would you like to go now?\n"},
	{"-------------------------------------------------------\nThe room is to dark to see anything..\nYou feel around but find nothing.\n"},
	{"-------------------------------------------------------\nYou walk into what appears to be an empty room..\n"},
	{"-------------------------------------------------------\nThe room appears to be empty..\n"},
	};

	roomdescription = EmptyRandomiser[rand()%4];
}
