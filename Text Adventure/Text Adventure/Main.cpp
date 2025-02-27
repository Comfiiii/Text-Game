#include <iostream>
#include <string>
#include "Game.h"

int main()
{
	srand(time(0));

	Game* TextAdventure = new Game();
	string Input;

	cout << "-------------------------------------------------------\n";
	cout << "Welcome to My Text Adventure!\nWould you like to play?\ny = yes   n = no\n";
	cin >> Input;

	while (Input != "y" && Input != "n")
	{
		system("cls");
		cout << "-------------------------------------------------------\n";
		cout << "Welcome to My Text Adventure!\nWould you like to play?\ny = yes   n = no\n";
		cout << "Invalid Input, Please use y/n.\n";
		Input.clear();
		cin >> Input;
	}

	if (Input == "y")
	{
		TextAdventure->gameplay = true;
		Input.clear();
		system("cls");
	}

	TextAdventure->Run();
	

}
