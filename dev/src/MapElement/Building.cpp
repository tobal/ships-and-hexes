
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
