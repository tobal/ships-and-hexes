
#ifndef MAPELEMENTFACTORY_HPP_
#define MAPELEMENTFACTORY_HPP_

#include <string>
#include "MapElement/Fighter.hpp"
#include "MapElement/Bomber.hpp"
#include "MapElement/Colonizer.hpp"
#include "MapElement/Planet.hpp"
#include "Empire/CommonTypes.hpp"
#include "Empire/Effect/Effect.hpp"

namespace MapElement
{

class MapElementFactory
{
private:
	std::string playerName;

public:
	MapElementFactory(std::string playerName);
	~MapElementFactory();
	Fighter* createFighter(const int count) const;
	Bomber* createBomber(const int count) const;
	Colonizer* createColonizer(const int count) const;
	Planet* createPlanet(PlanetType type, PlanetSize size, Empire::Effect::Effect* trait) const;
};

}

#endif /* MAPELEMENTFACTORY_HPP_ */
