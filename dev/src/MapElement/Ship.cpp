
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
	if( movePoints == -1 )
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
	if( getMovePoints() < toMove)
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
	int calc = count + toAdd;
	count = calc <= maxFleetSize ? calc : maxFleetSize;
}

void Ship::destroy(const int toDestroy)
{
	int calc = count - toDestroy;
	count = calc >= 0 ? calc : 0;
}

void Ship::mergeShips(Ship* otherShip)
{
	if (count + otherShip->getCount() <= maxFleetSize)
	{
		movePoints = movePoints < otherShip->getMovePoints() ? movePoints : otherShip->getMovePoints();
		addShips(otherShip->getCount());
	}
	else
	{
		throw CannotMergeShipsException("Cannot merge, fleets too large");
	}
}

void Ship::resetMoves()
{
	movePoints = getSpeed();
}
