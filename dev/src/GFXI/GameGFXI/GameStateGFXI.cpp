
#include "GFXI/GameGFXI/GameStateGFXI.hpp"

using namespace GameGFXI;
using namespace GameMap;
using namespace GameState;

GameStateGFXI::GameStateGFXI()
{
	gameState = dynamic_cast<GameState::GameState*>(new GameStateImpl());
}

GameStateGFXI::~GameStateGFXI()
{
	delete gameState;
}

GameMap::GameMap* GameStateGFXI::generateMap()
{
	return gameState->generateMap();
}
