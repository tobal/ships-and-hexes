
#include "MapElement/Planet.hpp"

using namespace MapElement;
using namespace std;
using namespace Empire::Effect;

// TODO get starting population from config
Planet::Planet(string playerName, PlanetType type, PlanetSize size, Effect* trait)
	: SpaceObject(playerName), type(type), size(size), trait(trait), population(1.0)
{
	buildingSlots = new BuildingSlots();
	int slots = 0;
	switch(size)
	{
	case SMALL:
		slots = 2;
		break;
	case MEDIUM:
		slots = 3;
		break;
	case LARGE:
		slots = 4;
		break;
	}
	for (int i = 0; i < slots; ++i)
	{
		 buildingSlots->push_back(new BuildingSlot(PLANET));
	}
}

Planet::~Planet()
{
	for (BuildingSlots::iterator slot = buildingSlots->begin(); slot != buildingSlots->end(); ++slot)
	{
		 delete (*slot);
	}
	delete buildingSlots;
}

PlanetType Planet::getPlanetType() const
{
	return type;
}

PlanetSize Planet::getPlanetSize() const
{
	return size;
}

Effect* Planet::getPlanetTrait() const
{
	return trait;
}

BuildingSlots* Planet::getBuildingSlots() const
{
	return buildingSlots;
}

float Planet::getPopulation() const
{
	return population;
}

void Planet::setPopulation(const float population)
{
	this->population = population;
}
