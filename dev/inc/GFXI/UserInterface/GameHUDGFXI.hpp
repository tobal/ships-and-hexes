
#ifndef GAMEHUDGFXI_HPP_
#define GAMEHUDGFXI_HPP_

#include "GFXI/GameGFXI/GameStateGFXI.hpp"

namespace UserInterface
{

enum ButtonId
{
	END_TURN
};

class GameHUDGFXI
{
private:
	GameGFXI::GameStateGFXI* gameState;
	void endTurn();

public:
	GameHUDGFXI(GameGFXI::GameStateGFXI* gameState);
	~GameHUDGFXI();
	void clickButton(ButtonId id);
};

}

#endif /* GAMEHUDGFXI_HPP_ */
