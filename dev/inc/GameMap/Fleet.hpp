
#ifndef FLEET_HPP_
#define FLEET_HPP_

#include <string>
#include <vector>
#include <algorithm>
#include "MapElement/MapElementFactory.hpp"
#include "MapElement/Fighter.hpp"
#include "MapElement/Bomber.hpp"
#include "MapElement/Colonizer.hpp"
#include "MapElement/Ship.hpp"

namespace GameMap
{

struct FleetCount
{
	FleetCount() : fighters(0), bombers(0), colonizers(0) {}
	FleetCount(int f, int b, int c) : fighters(f), bombers(b), colonizers(c) {}
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
	Fleet(FleetCount flc);
	~Fleet();

	MapElement::Fighter* getFighter() const;
	MapElement::Bomber* getBomber() const;
	MapElement::Colonizer* getColonizer() const;
	FleetCount getFleetCount() const;
	void addFleet(Fleet* fleet);
	void removeFleet(FleetCount flc);
	Fleet* splitFleet(FleetCount flc);
	int getMovePoints() const;
	void move(const int toMove) throw(OutOfMovePointsException);
	void resetMoves();
};

}

#endif /* FLEET_HPP_ */
