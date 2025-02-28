#include "Player.h"

Player::Player()
{

}

Player::~Player()
{

}

bool Player::FindSpell(std::string spell)
{
	int count = size(spells); 

	int left = 0;
	int right = count;

	while (left != right)
	{
		int middle = left + (right - left) / 2;
		if (spells[middle] == spell)
		{
			return true;
		}

		if (spell < spells[middle]) 
		{
			right = middle;
			continue;
		}

		left = middle + 1;
	}
	return false;
}

//int OldBinary(int* values, int valueToFind, std::size_t count)
//{
//
//	int left = 0;
//	int right = static_cast<int>(count);
//
//	while (left != right)
//	{
//		int middle = (right + left) / 2;
//
//		if (values[middle] == valueToFind)
//		{
//			return middle;
//		}
//
//		if (valueToFind < values[middle])
//		{
//			right = middle;
//			continue;
//		}
//		left = middle + 1;
//	}
//	return -1;
//}