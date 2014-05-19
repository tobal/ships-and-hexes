
#include "MapElement/Fighter.hpp"

using namespace MapElement;
using namespace std;

Fighter::Fighter(string playerName, const int count) : Ship(playerName, count)
{
	baseSpeed = 5;	// fighter base speed
}

Fighter::~Fighter()
{

}

void Fighter::merge(Fighter* otherFighter)
{
	this->mergeShips(otherFighter);
}
