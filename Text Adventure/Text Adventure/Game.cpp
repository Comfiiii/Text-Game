#include "Game.h"

Game::Game()
{
	Cat* cat = new Cat; 
	BoxOfDonuts* boxofdonuts = new BoxOfDonuts;
	Lamp* lamp = new Lamp;
	player = new Player;

	// Allocate objects to rooms 
	rooms[2][0].item = cat; 
	rooms[0][3].item = boxofdonuts;
	rooms[2][4].item = lamp;

	std::string EnemyRandomiser[4] =
	{
		{"-------------------------------------------------------\nThere is an enemy!\nYou pull out your sword and split it in two..\n"},
		{"-------------------------------------------------------\nYou spot an enemy!\nYou run towards it and stab it in the face..\n"},
		{"-------------------------------------------------------\nAn enemy jumps out before you!\nYou quickly end it before it hurts you...\n"},
		{"-------------------------------------------------------\nYou spot something in the dark..\n An enemy!\n It bites you and you throw it off and stab it through the heart..\n"},
	};

	std::string EmptyRandomiser[4] =
	{
	{"-------------------------------------------------------\nThis room is empty..\nWhere would you like to go now?\n"},
	{"-------------------------------------------------------\nThe room is to dark to see anything..\nYou feel around but find nothing.\n"},
	{"-------------------------------------------------------\nYou walk into what appears to be an empty room..\n"},
	{"-------------------------------------------------------\nThe room appears to be empty..\n"},
	};

	rooms[0][0].SetDescription("-------------------------------------------------------\nYou have found yourself alone in a dark room... where would you like to go?\nUse w to move up a room\nUse s to move down a room\nUse a to move left a room\nUse d to move right a room\nUse 'Inspect' to inspect your weapon..\n");
	
	rooms[0][3].SetDescription("-------------------------------------------------------\nThere is a seemingly endless box of donuts in here... do you want to eat one? if so type 'eat donut'\n");
	rooms[1][0].SetDescription(EmptyRandomiser[rand() % 4]);
	rooms[2][0].SetDescription("-------------------------------------------------------\nThere is a cat in here, type 'pet cat' to pet it\n");
	rooms[2][2].SetDescription(EmptyRandomiser[rand() % 4]);
	rooms[2][4].SetDescription("-------------------------------------------------------\nThere is a lamp in here, turn it on? if yes type 'turn on\n");
	rooms[3][1].SetDescription(EmptyRandomiser[rand() % 4]);
	rooms[3][4].SetDescription(EmptyRandomiser[rand() % 4]);
	rooms[3][5].SetDescription(EmptyRandomiser[rand() % 4]);

	rooms[0][2].SetDescription(EnemyRandomiser[rand() % 4]);
	rooms[0][4].SetDescription(EnemyRandomiser[rand() % 4]);
	rooms[1][2].SetDescription(EnemyRandomiser[rand() % 4]);
	rooms[2][3].SetDescription(EnemyRandomiser[rand() % 4]);
	rooms[2][5].SetDescription(EnemyRandomiser[rand() % 4]);
	rooms[3][0].SetDescription(EnemyRandomiser[rand() % 4]);
	rooms[3][2].SetDescription(EnemyRandomiser[rand() % 4]);
	rooms[4][4].SetDescription(EnemyRandomiser[rand() % 4]);

	rooms[4][0].SetDescription("-------------------------------------------------------\nYou run into a MiniBoss!\nYou fight hard and manage to slay it..\nIt drops a piece of armor that you equip.\n");

	rooms[4][2].SetDescription("-------------------------------------------------------\nYou feel your power surging and a light emitting from the room..\nIn the middle is a shiny sword in a stone!\nYou walk towards it and yank it out!\nYou feel you could kill anything, even a boss!\n");

	rooms[3][6].SetDescription("");

	rooms[1][5].SetDescription("-------------------------------------------------------\nYou run into a horde of enemies!\nIts a tough fight but with your sturdy sword and armor, you manage to kill them all..\nYou find a new shiny set of armor that you swap your old set with..\nYou feel a lot stronger now..\n");

	rooms[0][1].SetDescription("-------------------------------------------------------\nYou see a rusty sword on the ground..you pick it up and put it in your inventory.\nYou think to yourself, Maybe I can kill enemies to find my way out..\n");

}

Game::~Game()
{

}

void Game::Run()
{
	std::string Input;

	while (gameplay == true)
	{
		RoomCheck();
		DisplayText();
		std::cout << "-------------------------------------------------------\n";
		std::cout << "What do you do now:\nInspect Item (Inspect)\nMove Room (w,a,s,d)\n";
		HasMoved = false;
		getline(std::cin, Input);
		system("cls");
		RecieveInput(Input);
		std::cin.clear();
	}
	
	if (gameplay == false)
	{
		system("cls");
	}

	
}

void Game::RecieveInput(std::string Input)
{
	/*if (Input.length() == 0)
	{
		return;
	}*/


	if (Input == "w")
	{
		if (Rooms[PlayerLocation.x - 1][PlayerLocation.y] == 1)
		{
			PlayerLocation.x -= 1;
			HasMoved = true;
		}

		else
		{
			std::cout << "-------------------------------------------------------\n";
			std::cout << "Something is blocking your passage... go another way.\n";
		}

		return;
	}

	else if (Input == "s")
	{
		if (Rooms[PlayerLocation.x + 1][PlayerLocation.y] == 1)
		{
			PlayerLocation.x += 1;
			HasMoved = true;
		}
		else
		{
			std::cout << "-------------------------------------------------------\n";
			std::cout << "Something is blocking your passage... go another way.\n";
		}
		return;
	}
	else if (Input == "a")
	{
		if (Rooms[PlayerLocation.x][PlayerLocation.y - 1] == 1)
		{
			PlayerLocation.y -= 1;
			HasMoved = true;
		}
		else
		{
			std::cout << "-------------------------------------------------------\n";
			std::cout << "Something is blocking your passage... go another way.\n";
		}
		return;
	}
	else if (Input == "d")
	{
		if (Rooms[PlayerLocation.x][PlayerLocation.y + 1] == 1)
		{
			PlayerLocation.y += 1;
			HasMoved = true;
		}
		else
		{
			std::cout << "-------------------------------------------------------\n";
			std::cout << "Something is blocking your passage... go another way.\n";
		}
		return;
	}


	else if (Input == "inspect" || Input == "Inspect")
	{
		std::cout << "-------------------------------------------------------\n";
		std::cout << "Feature not yet implemented..\n";
	}

	else if (Input == "pet cat" && (PlayerLocation.x == 3 && PlayerLocation.y == 1)) 
	{
		rooms[2][0].item->Use();
	}

	else if (Input == "eat donut" && PlayerLocation.x == 1 && PlayerLocation.y == 4)
	{
		rooms[0][3].item->Use();
	}

	else if (Input == "turn on" && (PlayerLocation.x == 3 && PlayerLocation.y == 5))
	{
		rooms[2][4].item->Use();
	}

	else if (Input == "spells")
	{
		std::string spellcheck;
		std::string sillyStringBuis;

		getline(std::cin, spellcheck);
		sillyStringBuis = (player->FindSpell(spellcheck) ? "Found" : "Not Found");
		system("cls");

		std::cout << sillyStringBuis << "\n";
		Input.clear();
		spellcheck.clear();
	}

	else
	{
		std::cout << "-------------------------------------------------------\n";
		std::cout << "Invalid input.\n";
		std::cout << Input.length();
	}
	
	
}

void Game::DisplayText()
{
	rooms[PlayerLocation.x - 1][PlayerLocation.y - 1].Description();

	if (HasMoved)
	{
		rooms[PlayerLocation.x - 1][PlayerLocation.y - 1].UpdateDescription();
	}
	
}

void Game::RoomCheck()
{
	//sword room
	if (PlayerLocation.x == 1 && PlayerLocation.y == 2)
	{
		hasSword = true;
		return;
	}

	//first enemy room
	if (PlayerLocation.x == 4 && PlayerLocation.y == 1 && !hasSword)
	{
		std::string end;
		system("cls");
		std::cout << "-------------------------------------------------------\n";
		std::cout << "You ran into an enemy and couldn't attack it...\nMaybe some sort of weapon would of helped??\nLife is just so short for some..\nYou were just one of those weak, unlucky people..\nPress any key to close game\n";
		std::cout << "-------------------------------------------------------\n";
		std::cin >> end;
		gameplay = false;
		return;
	}

	//miniboss room (for armor)
	if (PlayerLocation.x == 5 && PlayerLocation.y == 1 && hasSword)
	{
		hasArmor = true;
		return;
	}
	
	//enemy horde room (for better armor)
	if (PlayerLocation.x == 2 && PlayerLocation.y == 6 && hasArmor)
	{
		hasBetterArmor = true;
		return;
	}
	if (PlayerLocation.x == 2 && PlayerLocation.y == 6 && !hasArmor)
	{
		std::string end = "";
		system("cls");
		std::cout << "-------------------------------------------------------\n";
		std::cout << "You stumbled into a room full of enemies\nYou were overwhelmed and crushed under the pressure of so many..\nMaybe some armor could of helped?\nOh well..\nYou're dead now..\nBetter luck next life.\nPress any key to exit.\n";
		std::cout << "-------------------------------------------------------\n";
		std::cin >> end;
		gameplay = false;
		return;
	}

	//better sword room (for better sword)
	if (PlayerLocation.x == 5 && PlayerLocation.y == 3 && hasBetterArmor)
	{
		hasBetterSword = true;
		return;
	}
	if (PlayerLocation.x == 5 && PlayerLocation.y == 3 && !hasBetterArmor)
	{
		std::string end = "";
		system("cls");
		std::cout << "-------------------------------------------------------\n";
		std::cout << "You feel your power surging and a light emitting from the room..\nIn the middle is a shiny sword in a stone!\nYou walk towards it and yank on it!\nBut you were unsuccessful pulling it out..\nThe overwhelming surge of power from the sword ripped your body apart..\nYou should of gotten stronger, you let that small bit of power get to your head didn't you huh?\nYou fool..\nThis is what you got.\nYou did this to yourself.\nPress any key to exit.\n";
		std::cout << "-------------------------------------------------------\n";
		std::cin >> end;
		gameplay = false;
		return;
	}

	//boss room (win)
	if (PlayerLocation.x == 4 && PlayerLocation.y == 7 && hasBetterSword)
	{
		std::string end = "";
		system("cls");
		std::cout << "-------------------------------------------------------\n";
		std::cout << "You run into a massive boss!.\nYou can feel its hot, disgusting breath from the door\nBut you do not feel scared and walk slowly towards it..\nYou draw your sword and run at it.\nYou jump on its back, as it picks you up and throws you to the ground..\nYou get up and run to the other side of the room..\nYou find a stone that you chuck at the boss, which stuns it for a second.\nYou take that chance to jump on its back again and stab your sword through its head, you push deeper into it to pierce its brain, finally killing it...\nAs the boss slumps to the ground, you spot a gate.\nYou walk towards it seeing daylight\nYou are finally free!\nYou win.\nPress any key to exit.\n";
		std::cout << "-------------------------------------------------------\n";
		std::cin >> end;
		gameplay = false;
		return;
	}
	if (PlayerLocation.x == 4 && PlayerLocation.y == 7 && !hasBetterSword)
	{
		std::string end = "";
		std::system("cls");
		std::cout << "-------------------------------------------------------\n";
		std::cout << "You stumble across a massive room with a huge boss in the middle\nBut you do not feel scared and approach it, you run at it slowly and jump on its back to try and kill it\nFool.\nThe boss grabs you by the legs and slams you into the ground, crushing half your head instantly...\nYou absolute, fool.\nYou thought you could win?\nOne shouldn't play with their life so easily..\nYou weak feeble human.\nYour death was on your own hands, It was only your fault.\nFool.\nMaybe you should of been scared..\nYou did this.\nYou are all there is to blame.\nBut oh well, no point worrying about it now, you are already dead...\nPress any key to exit.\n";
		std::cout << "-------------------------------------------------------\n";
		std::cin >> end;
		gameplay = false;
		return;
	}
}
