
#include "MapElement/Building.hpp"

using namespace std;
using namespace MapElement;
using namespace Empire::Effect;

Building::Building(BuildingType buildingType) : type(buildingType), complete(0)
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

int Building::getCompletePercent() const
{
	return complete;
}

void Building::setCompletePercent(const int complete)
{
	this->complete = complete;
}

void Building::addToCompletePercent(int toAdd)
{
	complete += toAdd;
}

bool Building::isComplete() const
{
	return complete == 100;
}
