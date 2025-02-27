#pragma once
#include <iostream>
#include <string>
using namespace std;
class Item
{
private:
	string itemdescription;
public:
	void ItemDesc() const;
	void Use();

	Item();
	virtual ~Item();
	
};