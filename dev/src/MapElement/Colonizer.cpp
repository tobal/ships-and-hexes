
#include "MapElement/Colonizer.hpp"

using namespace MapElement;
using namespace std;

Colonizer::Colonizer(const int count) : Ship(count)
{
	baseSpeed = 3;	// colonizer base speed
}

Colonizer::~Colonizer()
{

}

void Colonizer::merge(Colonizer* otherFighter)
{
	this->mergeShips(otherFighter);
}
