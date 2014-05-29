
#ifndef BUILDING_HPP_
#define BUILDING_HPP_

#include <vector>
#include <string>
#include <set>
#include "MapElement/MapElement.hpp"
#include "Empire/Effect/BuildingEffect.hpp"
#include "Empire/CommonTypes.hpp"
#include "Exceptions/CannotBuildException.hpp"

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

// TODO: circumvent this with a Buildable interface, or other pattern
const MapElementType buildables[] = {PLANET, SPACESTATION};
static const std::set<MapElementType> buildableMapElements(buildables, buildables + 2);

const BuildingType stationBuildingTypes[] = {STATION_MODULE_1, STATION_MODULE_2};
const int stationBuildingTypesRange = sizeof(stationBuildingTypes) / sizeof(stationBuildingTypes[0]);
static const std::set<BuildingType> stationBuildings(stationBuildingTypes, stationBuildingTypes + stationBuildingTypesRange);

const BuildingType planetBuildingTypes[] = {FIGHTER_FACTORY, BOMBER_FACTORY, CITY, RESEARCH_CENTER};
const int planetBuildingTypesRange = sizeof(planetBuildingTypes) / sizeof(planetBuildingTypes[0]);
static const std::set<BuildingType> planetBuildings(planetBuildingTypes, planetBuildingTypes + planetBuildingTypesRange);

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
	MapElementType type;
	Building* building;
	bool isIn(BuildingType type, std::set<BuildingType> types);

public:
	BuildingSlot(const MapElementType type);
	~BuildingSlot();
	Building* getBuilding() const;
	void build(BuildingType buildingType);
	void demolish();
};

typedef std::vector<BuildingSlot*> BuildingSlots;

}

#endif /* BUILDING_HPP_ */
