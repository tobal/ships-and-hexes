
#ifndef GAMEPLAY_HPP_
#define GAMEPLAY_HPP_

#include "GameMap/GameMap.hpp"

namespace Gameplay
{

class Gameplay
{
public:
	Gameplay() {}
	virtual ~Gameplay() {}
	// TODO interface for gameplay, commands, GameState will use this
	virtual void nextTurn(GameMap::GameMap* map) {}
};

}

#endif /* GAMEPLAY_HPP_ */
