
#ifndef MAPELEMENTFACTORY_HPP_
#define MAPELEMENTFACTORY_HPP_

#include <string>
#include "MapElement/Fleet.hpp"
#include "MapElement/Planet.hpp"
#include "MapElement/Anomaly.hpp"
#include "MapElement/SpaceStation.hpp"
#include "Empire/CommonTypes.hpp"
#include "Empire/Effect/Effect.hpp"
#include "Empire/Effect/ProductionBonus.hpp"
#include "Empire/Effect/PopulationBonus.hpp"
#include "Empire/Effect/ResearchBonus.hpp"

namespace MapElement
{

class Fleet;

class MapElementFactory
{
private:
	std::string playerName;

public:
	MapElementFactory(std::string playerName);
	~MapElementFactory();
	Fleet* createFleet(int fighterCount, int bomberCount, int colonizerCount);
	Planet* createPlanet(PlanetType type, PlanetSize size, Empire::Effect::Effect* trait) const;
	Anomaly* createAnomaly(AnomalyType type, AnomalySize size) const;
	SpaceStation* createStation() const;
};

}

#endif /* MAPELEMENTFACTORY_HPP_ */
