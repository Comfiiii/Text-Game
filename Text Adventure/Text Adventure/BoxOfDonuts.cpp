#include "Item.h"
#include "BoxOfDonuts.h"

BoxOfDonuts::BoxOfDonuts()
{

}

BoxOfDonuts::~BoxOfDonuts()
{

}

void BoxOfDonuts::Description() const
{
	std::cout << "This is a BoxOfDonuts\n";
}

void BoxOfDonuts::Use()
{
	bool eatDonut = false;
	if (eatDonut = true)
	{
		eatDonut = true;
		count--;
		std::cout << "-------------------------------------------------------\n";
		std::cout << "You ate a donut and there are only " << count << " left\n";
	}
}

