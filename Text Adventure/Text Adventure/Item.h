#pragma once
#include <iostream>
#include <string>
using namespace std;
class Item
{
private:
	string itemdescription;
public:
	void Description() const;
	void Use();

	Item();
	virtual ~Item();
	
};