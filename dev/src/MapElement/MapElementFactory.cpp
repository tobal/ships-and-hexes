
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

Fleet* MapElementFactory::createFleet(int fighterCount, int bomberCount, int colonizerCount)
{
	return new Fleet(playerName, fighterCount, bomberCount, colonizerCount);
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

SpaceStation* MapElementFactory::createStation() const
{
	return new SpaceStation(playerName);
}
