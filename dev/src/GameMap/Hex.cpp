
#include "GameMap/Hex.hpp"

using namespace GameMap;
using namespace MapElement;

Hex::Hex() : object(NULL), objectType(PLANET), fleet(NULL)
{
}

Hex::~Hex()
{
}

bool Hex::hasSpaceObject() const
{
	return object != NULL;
}

void Hex::addSpaceObject(Anomaly* anomaly)
{
	objectType = ANOMALY;
	object = anomaly;
}

void Hex::addSpaceObject(Planet* planet)
{
	objectType = PLANET;
	object = planet;
}

void Hex::addSpaceObject(SpaceStation* station)
{
	objectType = SPACESTATION;
	object = station;
}

MapElementType Hex::getSpaceObjectType() const
{
	return objectType;
}

SpaceObject* Hex::getSpaceObject() const
{
	return object;
}

void Hex::removeSpaceObject()
{
	delete object;
	object = NULL;
}
