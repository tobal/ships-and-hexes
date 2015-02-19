
#ifndef HUD_HPP_
#define HUD_HPP_

#include "GFX/OrxGFX/ObjectRepos.hpp"

namespace GameGraphics
{

class HudGFX
{
private:
	HUDObjectRepo* hudRepo;

public:
	HudGFX();
	~HudGFX();
	void drawHUD();
};

}

#endif /* HUD_HPP_ */
