#pragma once
#include <iostream>
#include <string>

class Item
{
private:
	std::string itemdescription;
public:
	virtual void Description() const;
	virtual void Use();

	Item();
	virtual ~Item();
	
};