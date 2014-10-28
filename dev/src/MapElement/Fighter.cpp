
#include "MapElement/Fighter.hpp"

using namespace MapElement;
using namespace std;

Fighter::Fighter(const int count) : Ship(count)
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
