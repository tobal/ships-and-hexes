
#include "GFX/OrxGFX/OrxMain.hpp"

using namespace GameMap;
using namespace MapElement;
using namespace Empire::Effect;
using namespace GameGFXI;
using namespace GameGraphics;
using namespace std;

orxVIEWPORT* viewport;
orxOBJECT* mouseCursor;

// TODO GameMapGFX
// TODO interface to GameplayGFXI
orxVECTOR translation = orxVECTOR_0;
orxVECTOR delta = orxVECTOR_0;

// TODO GameState.hpp
// TODO interface to GameGFXI
// TODO interface to GameplayGFXI
// TODO interface to Gameplay
GameMapGFX* mapGfx;
HudGFX* hudGfx;
GameStateGFXI* stateInterface;

// TODO Input.hpp
bool mbleftFlag = false;

void orxFASTCALL Update(const orxCLOCK_INFO *_pstClockInfo, void *_pstContext)
{
	orxVECTOR mousePos;
	orxMouse_GetPosition(&mousePos);

	mapGfx->updateMap(viewport, &delta);
	hudGfx->updateHud(&mousePos);

	if(orxRender_GetWorldPosition(&mousePos, viewport, &mousePos))
	{
		orxMouse_ShowCursor(false);
		orxVECTOR vParentPosition;
		orxObject_GetWorldPosition(mouseCursor, &vParentPosition);
		mousePos.fZ = vParentPosition.fZ;
		orxObject_SetPosition(mouseCursor, &mousePos);

		if(orxMouse_IsButtonPressed(orxMOUSE_BUTTON_LEFT))
		{
			// dragging
			orxMouse_GetMoveDelta(&delta);
			orxVector_Add(&translation, &translation, &delta);

			// clicking
			if(!mbleftFlag)
			{
				orxLOG("position: %f, %f", mousePos.fX, mousePos.fY);
			}
			mbleftFlag = true;
		}
		else
		{
			mbleftFlag = false;
			delta = orxVECTOR_0;
		}
	}
}

orxSTATUS orxFASTCALL Init()
{
	orxConfig_Load("cfg/mainConf.ini");
	viewport = orxViewport_CreateFromConfig("Viewport");

	mouseCursor = orxObject_CreateFromConfig("CursorObj");

	stateInterface = new GameStateGFXI();
	stateInterface->setGameMap(stateInterface->generateMap());

	// draw hud
	hudGfx = new HudGFX(stateInterface);
	hudGfx->drawHUD();

	// TODO make separate viewport for the map
	mapGfx = new GameMapGFX();
	mapGfx->drawMap(stateInterface->getGameMap());

	orxCLOCK *pstMainClock;
	pstMainClock = orxClock_FindFirst(orx2F(-1.0f), orxCLOCK_TYPE_CORE);
	orxClock_Register(pstMainClock, Update, orxNULL, orxMODULE_ID_MAIN, orxCLOCK_PRIORITY_NORMAL);

	return orxSTATUS_SUCCESS;
}

orxSTATUS orxFASTCALL Run()
{
	orxSTATUS eResult = orxSTATUS_SUCCESS;

	if(orxInput_IsActive("Quit"))
	{
		eResult = orxSTATUS_FAILURE;
	}

	return eResult;
}

void orxFASTCALL Exit()
{
	delete mapGfx;
	delete stateInterface;
	delete hudGfx;
}

int orxMain(int argc, char **argv)
{
	orx_Execute(argc, argv, Init, Run, Exit);
	return EXIT_SUCCESS;
}
