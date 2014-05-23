
#include "MapElement/Planet.hpp"

using namespace MapElement;
using namespace std;
using namespace Empire::Effect;

Planet::Planet(string playerName, PlanetType type, PlanetSize size, Effect* trait)
	: MapElement(playerName), type(type), size(size), trait(trait)
{
	buildings = new Buildings();
}

Planet::~Planet()
{
	delete buildings;
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

void Planet::build(BuildingType buildingType)
{
	Building* building = new Building(buildingType);
	buildings->push_back(building);
}

Buildings* Planet::getBuildings() const
{
	return buildings;
}
