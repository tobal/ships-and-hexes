
#ifndef GAMEMAP_HPP_
#define GAMEMAP_HPP_

#include "Empire/CommonTypes.hpp"

namespace GameMap
{

class GameMap
{
public:
	GameMap() {}
	virtual ~GameMap() {}
	Coord* getDimensions() {}
};

}

#endif /* GAMEMAP_HPP_ */
