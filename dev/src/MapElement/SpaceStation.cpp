
#include "MapElement/SpaceStation.hpp"

using namespace MapElement;
using namespace std;

SpaceStation::SpaceStation(string playerName)
	: MapElement(playerName), baseAura(3)
{
	buildingSlot = new BuildingSlot(SPACESTATION);
}

SpaceStation::~SpaceStation()
{
	delete buildingSlot;
}

int SpaceStation::getAura() const
{
	return baseAura;
}

BuildingSlot* SpaceStation::getBuildingSlot() const
{
	return buildingSlot;
}
