
#ifndef GAMEHUDGFXI_HPP_
#define GAMEHUDGFXI_HPP_

#include "GFXI/UserInterface/Button.hpp"
#include "GFXI/GameGFXI/GameStateGFXI.hpp"

namespace UserInterface
{

class GameHUDGFXI
{
private:
	GameGFXI::GameStateGFXI* gameState;

public:
	GameHUDGFXI(GameGFXI::GameStateGFXI* gameState);
	~GameHUDGFXI();
	void clickButton(ButtonId id);
};

}

#endif /* GAMEHUDGFXI_HPP_ */
