
#include "Empire/Effect/TwinPlanet.hpp"

using namespace Empire::Effect;
using namespace GameMap;
using namespace MapElement;
using namespace std;

TwinPlanet::TwinPlanet()
{

}

TwinPlanet::~TwinPlanet()
{

}

void TwinPlanet::applyEffect(GameMap::GameMap* map, Coord homeworld, Planet* planet)
{
	GameMapImpl* mapImpl = dynamic_cast<GameMapImpl*>(map);
	CircularMapIterator vicinity = mapImpl->getCircularIterator(homeworld, 2);
	while(vicinity.hasNext())
	{
		Coord coord = vicinity.nextCoord();
		Hex* hex = map->getHexOnCoord(coord);
		if(hex->getSpaceObjectType() == PLANET)
		{
			hex->removeSpaceObject();
			hex->addSpaceObject(planet);
			return;
		}
		if(!map->isObjectInVicinity(PLANET, coord, 1))
		{
			hex->addSpaceObject(planet);
			return;
		}
	}
	// TODO indicate error
}
