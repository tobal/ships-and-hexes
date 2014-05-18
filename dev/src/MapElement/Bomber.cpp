
#include "MapElement/Bomber.hpp"

using namespace MapElement;
using namespace std;

Bomber::Bomber(string playerName, const int count) : Ship(playerName, count)
{
	baseSpeed = 4;	// bomber base speed
}

Bomber::~Bomber()
{

}
