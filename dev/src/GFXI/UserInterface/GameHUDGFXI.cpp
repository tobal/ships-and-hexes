
#include "GFXI/UserInterface/GameHUDGFXI.hpp"

using namespace UserInterface;

GameHUDGFXI::GameHUDGFXI(GameGFXI::GameStateGFXI* gameState) : gameState(gameState)
{

}

GameHUDGFXI::~GameHUDGFXI()
{

}

void GameHUDGFXI::clickButton(ButtonId id)
{
	switch(id)
	{
	case END_TURN:
		endTurn();
		break;
	}
}

void GameHUDGFXI::endTurn()
{

}
