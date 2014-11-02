
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

namespace MapElement
{

struct FleetCount
{
	FleetCount() : fighters(0), bombers(0), colonizers(0) {}
	FleetCount(int f, int b, int c) : fighters(f), bombers(b), colonizers(c) {}
	int fighters;
	int bombers;
	int colonizers;
};

class Fleet : public MapElement
{
private:
	Fighter* fighter;
	Bomber* bomber;
	Colonizer* colonizer;

public:
	Fleet(std::string playerName, int fighters, int bombers, int colonizers);
	Fleet(std::string playerName, FleetCount flc);
	~Fleet();

	Fighter* getFighter() const;
	Bomber* getBomber() const;
	Colonizer* getColonizer() const;
	FleetCount getFleetCount() const;
	void mergeFleet(Fleet* fleet);
	void removeFleet(FleetCount flc);
	Fleet* splitFleet(FleetCount flc);
	int getMovePoints() const;
	void move(const int toMove) throw(OutOfMovePointsException);
	void resetMoves();
};

}

#endif /* FLEET_HPP_ */
