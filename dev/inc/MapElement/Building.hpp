
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
	NO_BUILDING,
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

class BuildingSlot
{
private:
	Building* building;

public:
	BuildingSlot();
	~BuildingSlot();
	Building* getBuilding() const;
	void build(BuildingType buildingType);
	void demolish();
};

typedef std::vector<BuildingSlot*> BuildingSlots;

}

#endif /* BUILDING_HPP_ */
