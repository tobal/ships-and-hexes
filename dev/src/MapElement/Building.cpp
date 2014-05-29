
#include "MapElement/Building.hpp"

using namespace std;
using namespace MapElement;
using namespace Empire::Effect;

Building::Building(BuildingType buildingType) : type(buildingType)
{
	// TODO: make appropriate effects for buildings
	switch(type)
	{
	case BOMBER_FACTORY:
		BuildingEffect* effect = new BuildingEffect();
		effects.push_back(effect);
	}
}

Building::~Building()
{
	for( vector<BuildingEffect*>::iterator it = effects.begin(); it != effects.end(); ++it)
	{
		delete *it;
	}
}

BuildingType Building::getType() const
{
	return type;
}

vector<BuildingEffect*> Building::getEffects() const
{
	return effects;
}



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
