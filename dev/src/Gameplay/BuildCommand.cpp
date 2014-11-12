
#include "Gameplay/BuildCommand.hpp"

using namespace Gameplay;
using namespace MapElement;

BuildCommand::BuildCommand(Coord colony, int slot, BuildingType bType)
 : colony(colony), slot(slot), bType(bType)
{

}

BuildCommand::~BuildCommand()
{

}

CommandResult BuildCommand::executeCommand(GameMap::GameMap* map)
{
	Planet* planet = dynamic_cast<Planet*>(map->getHexOnCoord(colony)->getSpaceObject());
	BuildingSlot* targetSlot;
	if(planet == NULL)
	{
		SpaceStation* planet = dynamic_cast<SpaceStation*>(map->getHexOnCoord(colony)->getSpaceObject());
		targetSlot = planet->getBuildingSlot();
	}
	else
	{
		targetSlot = planet->getBuildingSlots()->at(slot);
	}
	if(bType == NO_BUILDING)
	{
		targetSlot->demolish();
		return DEMOLISTSUCCESSFUL;
	}
	else
	{
		targetSlot->build(bType);
		return BUILDSUCCESSFUL;
	}
}

