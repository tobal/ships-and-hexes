
#ifndef SHIP_HPP_
#define SHIP_HPP_

#include <string>
#include "MapElement/MapElement.hpp"
#include "Exceptions/OutOfMovePointsException.hpp"
#include "Exceptions/CannotMergeShipsException.hpp"

namespace MapElement
{

class Ship
{
static const int maxFleetSize = 100;

protected:
	int baseSpeed;
	void mergeShips(Ship* otherShip);
	// TODO: put a pure virtual function here, to force subclasses to implement merge()

private:
	int bonusSpeed;
	int movePoints;
	int count;

public:
	Ship(const int count);
	virtual ~Ship();
	int getBaseSpeed() const;
	int getSpeed() const;
	int getMovePoints();
	int getCount() const;
	void move(const int toMove) throw(OutOfMovePointsException);
	void addShips(const int toAdd);
	void destroy(const int toDestroy);
	void resetMoves();
};

}

#endif /* SHIP_HPP_ */
