
#include "MapElement/BuildingSlot.hpp"

using namespace MapElement;
using namespace std;

BuildingSlot::BuildingSlot(const MapElementType type)
{
	if(buildableMapElements.find(type) == buildableMapElements.end())
	{
		// defaulted to PLANET
		this->type = PLANET;
	}
	else
	{
		this->type = type;
	}
	building = new Building(NO_BUILDING);
}

BuildingSlot::~BuildingSlot()
{
	delete building;
}

bool BuildingSlot::isIn(BuildingType type, set<BuildingType> types)
{
	return types.find(type) == types.end();
}

Building* BuildingSlot::getBuilding() const
{
	return building;
}

void BuildingSlot::build(BuildingType buildingType)
{
	if(building->getType() != NO_BUILDING)
	{
		throw CannotBuildException("Cannot build on not empty slot");
	}

	switch(type)
	{
	case PLANET:
		if(isIn(buildingType, planetBuildings))
		{
			throw CannotBuildException("Cannot build station building on planet slot");
		}
		break;
	case SPACESTATION:
		if(isIn(buildingType, stationBuildings))
		{
			throw CannotBuildException("Cannot build planet building on station slot");
		}
		break;
	}

	building = new Building(buildingType);
}

void BuildingSlot::demolish()
{
	delete building;
	building = new Building(NO_BUILDING);
}

int BuildingSlot::getComplete() const
{
	return building->getCompletePercent();
}

void BuildingSlot::addToComplete(int toAdd)
{
	if(building->getCompletePercent() + toAdd > 100)
	{
		building->setCompletePercent(100);
	}
	else
	{
		building->addToCompletePercent(toAdd);
	}
}

bool BuildingSlot::isComplete() const
{
	return building->isComplete();
}
