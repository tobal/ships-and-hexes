
#ifndef GAMEMAPIMPL_HPP_
#define GAMEMAPIMPL_HPP_

#include <vector>
#include "GameMap/GameMap.hpp"
#include "GameMap/Hex.hpp"
#include "Empire/CommonTypes.hpp"

namespace GameMap
{

typedef std::vector< HexVector* > HexMap;

class GameMapImpl : public GameMap
{
private:
	HexMap* hexMap;
	Coord* dimensions;

public:
	GameMapImpl(const int x, const int y);
	~GameMapImpl();
	Coord* getDimensions();
};

}

#endif /* GAMEMAPIMPL_HPP_ */
