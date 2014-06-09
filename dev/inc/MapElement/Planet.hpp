
#ifndef PLANET_HPP_
#define PLANET_HPP_

#include <vector>
#include <string>
#include "Empire/CommonTypes.hpp"
#include "Empire/Effect/Effect.hpp"
#include "MapElement/Building.hpp"
#include "MapElement/BuildingSlot.hpp"
#include "MapElement/SpaceObject.hpp"

namespace MapElement
{

class Planet : public SpaceObject
{
private:
	PlanetType type;
	PlanetSize size;
	Empire::Effect::Effect* trait;
	BuildingSlots* buildingSlots;

public:
	Planet(std::string playerName, PlanetType type, PlanetSize size, Empire::Effect::Effect* trait);
	~Planet();
	PlanetType getPlanetType() const;
	PlanetSize getPlanetSize() const;
	Empire::Effect::Effect* getPlanetTrait() const;
	BuildingSlots* getBuildingSlots() const;
};

}

#endif /* PLANET_HPP_ */
