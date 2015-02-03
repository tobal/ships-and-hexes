
#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_

#include "GameState/EmpireDetails.hpp"
#include "GameMap/GameMap.hpp"

namespace GameState
{

class GameState
{
public:
	GameState() {}
	virtual ~GameState() {}
	virtual EmpireDetails getEmpireDetails() {}
	virtual GameMap::GameMap* generateMap() {}
};

}

#endif /* GAMESTATE_HPP_ */
