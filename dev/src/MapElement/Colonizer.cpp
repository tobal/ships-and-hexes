
#include "MapElement/Colonizer.hpp"

using namespace MapElement;
using namespace std;

Colonizer::Colonizer(string playerName, const int count) : Ship(playerName, count)
{
	baseSpeed = 3;	// colonizer base speed
}

Colonizer::~Colonizer()
{

}
