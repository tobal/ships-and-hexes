
#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_

#include "GameState/EmpireDetails.hpp"
#include "GameMap/GameMapImpl.hpp"
#include "GameMap/GameMapGenerator.hpp"
#include "GameConfig/Player.hpp"
#include <vector>

namespace GameState
{

class GameState
{
public:
	GameState() {}
	virtual ~GameState() {}
	virtual EmpireDetails getEmpireDetails() {}
	virtual GameMap::GameMapImpl* generateMap() {}
};

}

#endif /* GAMESTATE_HPP_ */
