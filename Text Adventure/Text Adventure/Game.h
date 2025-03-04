#pragma once
#include <iostream>
#include <string>
#include "Room.h"
#include "Player.h"
#include "Cat.h"
#include "BoxOfDonuts.h"
#include "Lamp.h"
#include "Item.h"

struct Vec2
{
public:
	int x;
	int y;
};


class Game
{
private:

	int Rooms[7][9] =
	{
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 0, 0, 0},
	{0, 1, 0, 1, 0, 0, 1, 0, 0},
	{0, 1, 0, 1, 1, 1, 1, 0, 0},
	{0, 1, 1, 1, 0, 1, 1, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	};

	Room rooms[5][7];

	Player* player;

	bool hasSword = false;
	bool hasArmor = false;
	bool hasBetterSword = false;
	bool hasBetterArmor = false;
	

public:
	bool gameplay = false;
	Vec2 PlayerLocation = { 1,1 };

	bool HasMoved = true;
	

	Game();
	~Game();
	void Run();

	void RecieveInput(std::string Input);
	void DisplayText();
	void RoomCheck();
};