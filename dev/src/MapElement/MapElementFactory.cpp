
#include "MapElement/MapElementFactory.hpp"

using namespace MapElement;
using namespace std;
using namespace Empire::Effect;

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

Planet* MapElementFactory::createPlanet(PlanetType type, PlanetSize size, Effect* trait) const
{
	return new Planet(playerName, type, size, trait);
}

Anomaly* MapElementFactory::createAnomaly(AnomalyType type, AnomalySize size) const
{
	EmpireEffect* effect;
	switch(type)
	{
	case ASTEROIDFIELD:
		effect = new ProductionBonus();
		break;
	case GASCLOUD:
		effect = new PopulationBonus();
		break;
	case ALIENWRECK:
		effect = new ResearchBonus();
		break;
	}
	return new Anomaly(playerName, type, size, effect);
}
