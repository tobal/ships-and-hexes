
#ifndef FLEET_HPP_
#define FLEET_HPP_

#include <string>
#include "MapElement/MapElementFactory.hpp"
#include "MapElement/Fighter.hpp"
#include "MapElement/Bomber.hpp"
#include "MapElement/Colonizer.hpp"

namespace GameMap
{

struct FleetCount
{
	int fighters;
	int bombers;
	int colonizers;
};

class Fleet
{
private:
	MapElement::Fighter* fighter;
	MapElement::Bomber* bomber;
	MapElement::Colonizer* colonizer;

public:
	Fleet(int fighters, int bombers, int colonizers);
	~Fleet();
	FleetCount getFleetCount() const;
};

}

#endif /* FLEET_HPP_ */
