
#ifndef BUILDING_HPP_
#define BUILDING_HPP_

#include <vector>
#include <string>
#include "MapElement/MapElement.hpp"
#include "Empire/Effect/BuildingEffect.hpp"

namespace MapElement
{

enum BuildingType
{
	FIGHTER_FACTORY,
	BOMBER_FACTORY,
	CITY,
	RESEARCH_CENTER
};

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
