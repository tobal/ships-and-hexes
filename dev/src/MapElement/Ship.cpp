
#include "MapElement/Ship.hpp"

using namespace MapElement;
using namespace std;

Ship::Ship(string playerName, const int count)
	: MapElement(playerName), bonusSpeed(0), movePoints(-1), count(count)
{

}

Ship::~Ship()
{

}

int Ship::getBaseSpeed() const
{
	return baseSpeed;
}

int Ship::getSpeed() const
{
	return baseSpeed + bonusSpeed;
}

int Ship::getMovePoints()
{
	if(movePoints == -1)
	{
		movePoints = baseSpeed + bonusSpeed;
	}
	return movePoints;
}

int Ship::getCount() const
{
	return count;
}
