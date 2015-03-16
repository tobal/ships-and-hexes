
#ifndef GAMEPLAYIMPL_HPP_
#define GAMEPLAYIMPL_HPP_

#include "Gameplay/Gameplay.hpp"
#include "Gameplay/Turn.hpp"
#include "GameMap/GameMap.hpp"

namespace Gameplay
{

class GameplayImpl : public Gameplay
{
private:
	Turn* turn;

public:
	GameplayImpl();
	~GameplayImpl();
	void nextTurn(GameMap::GameMap* map);
};

}

#endif /* GAMEPLAYIMPL_HPP_ */
