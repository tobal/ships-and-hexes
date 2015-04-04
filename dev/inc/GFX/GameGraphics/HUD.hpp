
#ifndef HUD_HPP_
#define HUD_HPP_

#include "GFX/OrxGFX/ObjectRepos.hpp"
#include "GFXI/UserInterface/GameHUDGFXI.hpp"
#include "GFXI/GameGFXI/GameStateGFXI.hpp"
#include "GFX/UIGFX/Button.hpp"
#include <string>

namespace GameGraphics
{

class HudGFX
{
private:
	HUDObjectRepo* hudRepo;
	UserInterface::GameHUDGFXI* hudGFXI;

public:
	HudGFX(GameGFXI::GameStateGFXI* stateInterface);
	~HudGFX();
	void drawHUD();
};

}

#endif /* HUD_HPP_ */
