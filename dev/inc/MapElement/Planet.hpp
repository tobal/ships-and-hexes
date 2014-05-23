
#ifndef PLANET_HPP_
#define PLANET_HPP_

#include <vector>
#include <string>
#include "MapElement/MapElement.hpp"
#include "Empire/CommonTypes.hpp"
#include "Empire/Effect/Effect.hpp"
#include "MapElement/Building.hpp"

namespace MapElement
{

class Planet : public MapElement
{
private:
	PlanetType type;
	PlanetSize size;
	Empire::Effect::Effect* trait;
	Buildings* buildings;

public:
	Planet(std::string playerName, PlanetType type, PlanetSize size, Empire::Effect::Effect* trait);
	~Planet();
	PlanetType getPlanetType() const;
	PlanetSize getPlanetSize() const;
	Empire::Effect::Effect* getPlanetTrait() const;
	void build(BuildingType building);
	Buildings* getBuildings() const;
};

}

#endif /* PLANET_HPP_ */
