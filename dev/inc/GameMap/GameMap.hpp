
#ifndef GAMEMAP_HPP_
#define GAMEMAP_HPP_

#include "Empire/CommonTypes.hpp"
#include "GameMap/Hex.hpp"

namespace GameMap
{

class GameMap
{
public:
	GameMap() {}
	virtual ~GameMap() {}
	virtual Coord getDimensions() {}
	virtual Hex* getHexOnCoord(Coord coord) {}
	virtual bool isObjectInVicinity(MapElementType type, Coord coord, int radius) {}
	virtual Coords getPlanets() {}
	virtual int countPlanetsOfPlayer(std::string playerName) {}
	virtual Coords getPlanetsOfPlayer(std::string playerName) {}
	virtual Coord getNextOnTrail(Coord source, Coord destination) {}
	virtual Coords getObjects(MapElementType type) {}
	virtual Coords getFleets() {}
	virtual Coords getSpaceStations() {}
};

}

#endif /* GAMEMAP_HPP_ */
