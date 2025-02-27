#pragma once
#include <iostream>
#include <string>
#include "Room.h"
#include "Player.h"
using namespace std;

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

	Room roomarray[5][7];

	Player* player;

	bool hasSword = false;
	bool hasArmor = false;
	bool hasBetterSword = false;
	bool hasBetterArmor = false;
	

public:
	bool gameplay = false;
	Vec2 PlayerLocation = { 1,1 };

	bool HasMoved = false;

	Game();
	~Game();
	void Run();

	void RecieveInput(string Input);
	void DisplayText();
	void RoomCheck();
};