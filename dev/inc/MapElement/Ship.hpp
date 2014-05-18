
#ifndef SHIP_HPP_
#define SHIP_HPP_

#include <string>
#include "MapElement/MapElement.hpp"

namespace MapElement
{

class Ship : public MapElement
{
protected:
	int baseSpeed;

private:
	int bonusSpeed;
	int movePoints;
	int count;

public:
	Ship(std::string playerName, const int count);
	virtual ~Ship();
	int getBaseSpeed() const;
	int getSpeed() const;
	int getMovePoints();
	int getCount() const;
};

}

#endif /* SHIP_HPP_ */
