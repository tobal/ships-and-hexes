
#ifndef SPACESTATION_HPP_
#define SPACESTATION_HPP_

#include <string>
#include "MapElement/SpaceObject.hpp"
#include "MapElement/BuildingSlot.hpp"

namespace MapElement
{

class SpaceStation : public SpaceObject
{
private:
	int baseAura;
	BuildingSlot* buildingSlot;

public:
	SpaceStation(std::string playerName);
	~SpaceStation();
	int getAura() const;
	BuildingSlot* getBuildingSlot() const;
};

}

#endif /* SPACESTATION_HPP_ */
