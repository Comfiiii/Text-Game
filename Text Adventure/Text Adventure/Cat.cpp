#include "Item.h"
#include "Cat.h"

Cat::Cat()
{

}

Cat::~Cat()
{

}

const void Cat::Description()
{
	std::cout << "This is a cat\n";
}

void Cat::Use()
{
		purring = true;
		if (purring == true)
		{
			std::cout << "-------------------------------------------------------\n";
			std::cout << "You pet the cat and it starts purring..\nThen it gets up and runs away..\n";
		}
		else
		{
			std::cout << "The cat is not purring\n";
		}
}