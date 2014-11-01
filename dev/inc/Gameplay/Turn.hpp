
#ifndef TURN_HPP_
#define TURN_HPP_

#include "GameMap/GameMap.hpp"
#include "MapElement/Fleet.hpp"

namespace Gameplay
{

class Turn
{
public:
	Turn();
	~Turn();
	void nextTurn(GameMap::GameMap* map);
};

}

#endif /* TURN_HPP_ */
