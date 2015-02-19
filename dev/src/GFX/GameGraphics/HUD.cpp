
#include "GFX/GameGraphics/HUD.hpp"

using namespace GameGraphics;

HudGFX::HudGFX()
{
	hudRepo = new HUDObjectRepo();
}

HudGFX::~HudGFX()
{
	delete hudRepo;
}

void HudGFX::drawHUD()
{
	orxVECTOR pos;
	pos.fX = 100.0;
	pos.fY = 100.0;
	pos.fZ = 0.0;
	orxOBJECT *endturnObj;
	endturnObj = orxObject_CreateFromConfig("HUDEndTurnObj");
	hudRepo->saveToRepo(endturnObj, pos);
	orxObject_SetPosition(endturnObj, &pos);
}
