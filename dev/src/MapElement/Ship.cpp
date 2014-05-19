
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

void Ship::move(const int toMove) throw(OutOfMovePointsException)
{
	if( movePoints < toMove)
	{
		int moved = movePoints;
		movePoints = 0;
		throw OutOfMovePointsException("Out of move points", moved, toMove - moved);
	}
	else
	{
		movePoints -= toMove;
	}
}

void Ship::addShips(const int toAdd)
{
	count += toAdd;
}

void Ship::destroy(const int toDestroy)
{
	count -= toDestroy;
}

void Ship::mergeShips(Ship* otherShip)
{
	int maxFleetSize = 100;		// TODO: put this somewhere else
	if (count + otherShip->getCount() <= 100)
	{
		movePoints = movePoints < otherShip->getMovePoints() ? movePoints : otherShip->getMovePoints();
		count += otherShip->getCount();
	}
	else
	{
		throw CannotMergeShipsException("Cannot merge, fleets too large");
	}
}
