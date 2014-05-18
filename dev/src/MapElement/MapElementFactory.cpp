
#include "MapElement/MapElementFactory.hpp"

using namespace MapElement;
using namespace std;

MapElementFactory::MapElementFactory(string playerName) : playerName(playerName)
{

}

MapElementFactory::~MapElementFactory()
{

}

Fighter* MapElementFactory::createFighter(const int count) const
{
	return new Fighter(playerName, count);
}

Bomber* MapElementFactory::createBomber(const int count) const
{
	return new Bomber(playerName, count);
}

Colonizer* MapElementFactory::createColonizer(const int count) const
{
	return new Colonizer(playerName, count);
}
