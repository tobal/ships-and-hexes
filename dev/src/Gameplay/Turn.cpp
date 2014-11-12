
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
	// TODO: put getBuildingSlots into SpaceObject, to use it polymorphically
	Coords planetCoords = map->getPlanets();
	for(Coords::iterator planetCoord = planetCoords.begin(); planetCoord != planetCoords.end(); ++planetCoord)
	{
		Planet* planet = dynamic_cast<Planet*>(map->getHexOnCoord(*planetCoord)->getSpaceObject());
		BuildingSlots* slots = planet->getBuildingSlots();
		for(BuildingSlots::iterator slot = slots->begin(); slot != slots->end(); ++slot)
		{
			// TODO: get value from configuration
			(*slot)->addToComplete(25);
		}
	}
	Coords stationCoords = map->getSpaceStations();
	for(Coords::iterator stationCoord = stationCoords.begin(); stationCoord != stationCoords.end(); ++stationCoord)
	{
		SpaceStation* station = dynamic_cast<SpaceStation*>(map->getHexOnCoord(*stationCoord)->getSpaceObject());
		BuildingSlot* slot = station->getBuildingSlot();
		// TODO: get value from configuration
		slot->addToComplete(25);
	}
}
