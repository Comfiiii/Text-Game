#include <iostream>
#include <string>
#include "Game.h"

int main()
{
	srand(time(0));

	Game* TextAdventure = new Game();
	std::string Input;

	std::cout << "-------------------------------------------------------\n";
	std::cout << "Welcome to My Text Adventure!\nWould you like to play?\ny = yes   n = no\n";
	getline(std::cin, Input);

	while (Input != "y" && Input != "n")
	{
		system("cls");
		std::cout << "-------------------------------------------------------\n";
		std::cout << "Welcome to My Text Adventure!\nWould you like to play?\ny = yes   n = no\n";
		std::cout << "Invalid Input, Please use y/n.\n";
		Input.clear();
		std::cin >> Input;
	}

	if (Input == "y")
	{
		TextAdventure->gameplay = true;
		Input.clear();
		system("cls");
	}

	TextAdventure->Run();
	

}
