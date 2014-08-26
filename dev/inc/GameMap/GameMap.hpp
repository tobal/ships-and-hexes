
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
	virtual int countPlanetsOfPlayer(std::string playerName) {}
	virtual Coords getPlanets() {}
};

}

#endif /* GAMEMAP_HPP_ */
