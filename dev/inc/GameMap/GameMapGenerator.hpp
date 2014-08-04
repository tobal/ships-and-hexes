
#ifndef GAMEMAPGENERATOR_HPP_
#define GAMEMAPGENERATOR_HPP_

#include "GameMap/GameMap.hpp"
#include "GameMap/GameMapImpl.hpp"
#include "GameMap/Hex.hpp"
#include "Empire/CommonTypes.hpp"

namespace GameMap
{

class GameMapGenerator
{
public:
	GameMapGenerator();
	~GameMapGenerator();
	GameMap* generateMap(const Coord& dimensions) const;
};

}


#endif /* GAMEMAPGENERATOR_HPP_ */
