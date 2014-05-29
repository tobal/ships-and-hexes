
#ifndef BUILDING_HPP_
#define BUILDING_HPP_

#include <vector>
#include "MapElement/MapElement.hpp"
#include "Empire/Effect/BuildingEffect.hpp"
#include "Empire/CommonTypes.hpp"

namespace MapElement
{

enum BuildingType
{
	NO_BUILDING,
	FIGHTER_FACTORY,
	BOMBER_FACTORY,
	CITY,
	RESEARCH_CENTER,
	STATION_MODULE_1,
	STATION_MODULE_2
};		// TODO: look up building types

class Building
{
private:
	BuildingType type;
	std::vector<Empire::Effect::BuildingEffect*> effects;

public:
	Building(BuildingType buildingType);
	~Building();
	BuildingType getType() const;
	std::vector<Empire::Effect::BuildingEffect*> getEffects() const;
};

typedef std::vector<Building*> Buildings;

}

#endif /* BUILDING_HPP_ */
