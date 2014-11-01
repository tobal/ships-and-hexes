
#include "Gameplay/Turn.hpp"

using namespace Gameplay;
using namespace MapElement;

Turn::Turn()
{

}

Turn::~Turn()
{

}

void Turn::nextTurn(GameMap::GameMap* map)
{
	Coords fleetCoords = map->getFleets();
	for(Coords::iterator fleetCoord = fleetCoords.begin(); fleetCoord != fleetCoords.end(); ++fleetCoord)
	{
		Fleet* fleet = map->getHexOnCoord(*fleetCoord)->getFleet();
		fleet->resetMoves();
	}
}
