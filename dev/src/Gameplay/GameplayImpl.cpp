
#include "Gameplay/GameplayImpl.hpp"

using namespace Gameplay;
using namespace GameMap;

GameplayImpl::GameplayImpl()
{
	turn = new Turn();
}

GameplayImpl::~GameplayImpl()
{
	delete turn;
}

void GameplayImpl::nextTurn(GameMap::GameMap* map)
{
	turn->nextTurn(map);
}
