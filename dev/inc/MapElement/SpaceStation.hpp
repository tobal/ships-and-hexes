
#ifndef SPACESTATION_HPP_
#define SPACESTATION_HPP_

#include <string>
#include "MapElement/MapElement.hpp"
#include "MapElement/Building.hpp"

namespace MapElement
{

class SpaceStation : public MapElement
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
