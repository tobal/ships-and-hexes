
#ifndef HEX_HPP_
#define HEX_HPP_

#include <vector>
#include "MapElement/SpaceObject.hpp"
#include "MapElement/Anomaly.hpp"
#include "MapElement/Planet.hpp"
#include "MapElement/SpaceStation.hpp"
#include "GameMap/Fleet.hpp"

namespace GameMap
{

class Hex
{
private:
	MapElement::SpaceObject* object;
	MapElementType objectType;
	Fleet* fleet;

public:
	Hex();
	~Hex();
	bool hasSpaceObject() const;
	void addSpaceObject(MapElement::Anomaly* anomaly);
	void addSpaceObject(MapElement::Planet* planet);
	void addSpaceObject(MapElement::SpaceStation* station);
	MapElementType getSpaceObjectType() const;
	MapElement::SpaceObject* getSpaceObject() const;
	void removeSpaceObject();
	bool hasFleet() const;
	void addFleet(Fleet* fleet);
	Fleet* getFleet() const;
	Fleet* moveOutFleet();
	void destroyFleet();
};

typedef std::vector<Hex*> HexVector;

}

#endif /* HEX_HPP_ */
