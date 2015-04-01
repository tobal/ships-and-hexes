
#ifndef GAMESTATEIMPL_HPP_
#define GAMESTATEIMPL_HPP_

#include "GameState/GameState.hpp"
#include "GameState/EmpireDetails.hpp"
#include "GameMap/GameMap.hpp"
#include "GameMap/GameMapGenerator.hpp"
#include "GameConfig/Player.hpp"
#include <vector>

namespace GameState
{

class GameStateImpl : public GameState
{
private:
	GameMap::GameMap* gameMap;

public:
	GameStateImpl();
	~GameStateImpl();
	EmpireDetails getEmpireDetails();
	GameMap::GameMap* generateMap();
	GameMap::GameMap* getGameMap();
	void setGameMap(GameMap::GameMap* gameMap);
};

}

#endif /* GAMESTATEIMPL_HPP_ */
