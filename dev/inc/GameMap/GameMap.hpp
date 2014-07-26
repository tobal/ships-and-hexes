
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
	Coord* getDimensions() {}
	Hex* getHexOnCoord(Coord coord) {}
};

}

#endif /* GAMEMAP_HPP_ */
