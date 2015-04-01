
#ifndef GAMESTATEGFXI_HPP_
#define GAMESTATEGFXI_HPP_

#include "GameMap/GameMap.hpp"
#include "GameState/GameState.hpp"
#include "GameState/GameStateImpl.hpp"

namespace GameGFXI
{

class GameStateGFXI
{
private:
	GameState::GameState* gameState;

public:
	GameStateGFXI();
	~GameStateGFXI();
	GameMap::GameMap* generateMap();
	GameMap::GameMap* getGameMap();
	void setGameMap(GameMap::GameMap* gameMap);
};

}

#endif /* GAMESTATEGFXI_HPP_ */
