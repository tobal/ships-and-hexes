
#include "Gameplay/Turn.hpp"
#include "Gameplay/GameplayConfig.hpp"

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
	Coords planetCoords = map->getPlanets();
	for(Coords::iterator planetCoord = planetCoords.begin(); planetCoord != planetCoords.end(); ++planetCoord)
	{
		Planet* planet = dynamic_cast<Planet*>(map->getHexOnCoord(*planetCoord)->getSpaceObject());
		BuildingSlots* slots = planet->getBuildingSlots();
		for(BuildingSlots::iterator slot = slots->begin(); slot != slots->end(); ++slot)
		{
			(*slot)->addToComplete(GameplayConfig().turn.planetBuildSpeed);
		}

		planet->setPopulation(planet->getPopulation() + GameplayConfig().turn.basePopIncrese);
	}
	Coords stationCoords = map->getSpaceStations();
	for(Coords::iterator stationCoord = stationCoords.begin(); stationCoord != stationCoords.end(); ++stationCoord)
	{
		SpaceStation* station = dynamic_cast<SpaceStation*>(map->getHexOnCoord(*stationCoord)->getSpaceObject());
		BuildingSlot* slot = station->getBuildingSlot();
		slot->addToComplete(GameplayConfig().turn.stationBuildSpeed);
	}
}
