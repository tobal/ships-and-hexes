
#include "GFX/GameGraphics/HUD.hpp"

using namespace std;
using namespace GameGraphics;
using namespace UserInterface;
using namespace GameGFXI;
using namespace UIGFX;

HudGFX::HudGFX(GameStateGFXI* stateInterface)
{
	hudRepo = new HUDObjectRepo();
	hudGFXI = new GameHUDGFXI(stateInterface);
}

HudGFX::~HudGFX()
{
	delete hudRepo;
}

void HudGFX::drawHUD()
{
	int screenWidth = 1280;
	int screenHeight = 720;
	float bottomPos = screenWidth - 167.0 - screenWidth/2;
	float edgePos = screenHeight - 86.0 - 47.0 - screenHeight/2;
	orxVECTOR pos;
	pos.fX = bottomPos;
	pos.fY = edgePos;
	pos.fZ = 0.0;


	orxOBJECT *endturnObj;
	endturnObj = orxObject_CreateFromConfig("HUDEndTurnObj");
	hudRepo->saveToRepo(endturnObj, pos);
	orxObject_SetPosition(endturnObj, &pos);

	float bottomOffset = bottomPos + screenWidth/2;
	orxLOG("HUD: %f, %f, %f", bottomPos, edgePos, bottomOffset);

	orxOBJECT *bottomLeftEdgeObj;
	bottomLeftEdgeObj = orxObject_CreateFromConfig("HUDBottomLeftEdgeObj");
	pos.fX = bottomPos - bottomOffset;
	hudRepo->saveToRepo(bottomLeftEdgeObj, pos);
	orxObject_SetPosition(bottomLeftEdgeObj, &pos);
	pos.fX += 4;

	orxOBJECT *bottomDisplayObj;
	bottomDisplayObj = orxObject_CreateFromConfig("HUDBottomDisplayObj");
	hudRepo->saveToRepo(bottomDisplayObj, pos);
	orxObject_SetPosition(bottomDisplayObj, &pos);
	pos.fX += 160;

	for (int i = 0; i < 30; ++i)
	{
		orxOBJECT *bottomSpacer5Obj;
		bottomSpacer5Obj = orxObject_CreateFromConfig("HUDBottomSpacer5Obj");
		hudRepo->saveToRepo(bottomSpacer5Obj, pos);
		orxObject_SetPosition(bottomSpacer5Obj, &pos);
		pos.fX += 5;
	}

	bottomDisplayObj = orxObject_CreateFromConfig("HUDBottomDisplayObj");
	hudRepo->saveToRepo(bottomDisplayObj, pos);
	orxObject_SetPosition(bottomDisplayObj, &pos);
	pos.fX += 160;

	for (int i = 0; i < 30; ++i)
	{
		orxOBJECT *bottomSpacer5Obj;
		bottomSpacer5Obj = orxObject_CreateFromConfig("HUDBottomSpacer5Obj");
		hudRepo->saveToRepo(bottomSpacer5Obj, pos);
		orxObject_SetPosition(bottomSpacer5Obj, &pos);
		pos.fX += 5;
	}

	bottomDisplayObj = orxObject_CreateFromConfig("HUDBottomDisplayObj");
	hudRepo->saveToRepo(bottomDisplayObj, pos);
	orxObject_SetPosition(bottomDisplayObj, &pos);
	pos.fX += 160;

	for (int i = 0; i < 65; ++i)
	{
		orxOBJECT *bottomSpacer5Obj;
		bottomSpacer5Obj = orxObject_CreateFromConfig("HUDBottomSpacer5Obj");
		hudRepo->saveToRepo(bottomSpacer5Obj, pos);
		orxObject_SetPosition(bottomSpacer5Obj, &pos);
		pos.fX += 5;
	}

	orxOBJECT *bottomRightEdgeObj;
	bottomRightEdgeObj = orxObject_CreateFromConfig("HUDBottomRightEdgeObj");
	pos.fX = bottomPos - 4;
	hudRepo->saveToRepo(bottomRightEdgeObj, pos);
	orxObject_SetPosition(bottomRightEdgeObj, &pos);





	float edgeOffset = -screenHeight/2;
	orxLOG("EDGE: %f, %f, %f", edgePos, screenHeight, edgeOffset);
	pos.fX = bottomPos;
	pos.fY = edgeOffset;

	orxOBJECT *rightTopEdgeObj;
	rightTopEdgeObj = orxObject_CreateFromConfig("HUDRightTopEdgeObj");
	hudRepo->saveToRepo(rightTopEdgeObj, pos);
	orxObject_SetPosition(rightTopEdgeObj, &pos);
	pos.fY += 3;

//	for (int i = 0; i < 1; ++i)
//	{
//		orxOBJECT *rightSpacer5Obj;
//		rightSpacer5Obj = orxObject_CreateFromConfig("HUDRightSpacer5Obj");
//		hudRepo->saveToRepo(rightSpacer5Obj, pos);
//		orxObject_SetPosition(rightSpacer5Obj, &pos);
//		pos.fY += 5;
//	}

	orxOBJECT *rightDisplayMediumObj;
	rightDisplayMediumObj = orxObject_CreateFromConfig("HUDRightDisplayMediumObj");
	hudRepo->saveToRepo(rightDisplayMediumObj, pos);
	orxObject_SetPosition(rightDisplayMediumObj, &pos);
	pos.fY += 135;

//	for (int i = 0; i < 1; ++i)
//	{
//		orxOBJECT *rightSpacer5Obj;
//		rightSpacer5Obj = orxObject_CreateFromConfig("HUDRightSpacer5Obj");
//		hudRepo->saveToRepo(rightSpacer5Obj, pos);
//		orxObject_SetPosition(rightSpacer5Obj, &pos);
//		pos.fY += 5;
//	}

	orxOBJECT *rightDisplaySmallObj;
	rightDisplaySmallObj = orxObject_CreateFromConfig("HUDRightDisplaySmallObj");
	hudRepo->saveToRepo(rightDisplaySmallObj, pos);
	orxObject_SetPosition(rightDisplaySmallObj, &pos);
	pos.fY += 39;

//	for (int i = 0; i < 1; ++i)
//	{
//		orxOBJECT *rightSpacer5Obj;
//		rightSpacer5Obj = orxObject_CreateFromConfig("HUDRightSpacer5Obj");
//		hudRepo->saveToRepo(rightSpacer5Obj, pos);
//		orxObject_SetPosition(rightSpacer5Obj, &pos);
//		pos.fY += 5;
//	}

	orxOBJECT *rightDisplaySmall2Obj;
	rightDisplaySmall2Obj = orxObject_CreateFromConfig("HUDRightDisplaySmall2Obj");
	hudRepo->saveToRepo(rightDisplaySmall2Obj, pos);
	orxObject_SetPosition(rightDisplaySmall2Obj, &pos);
	pos.fY += 41;

//	for (int i = 0; i < 1; ++i)
//	{
//		orxOBJECT *rightSpacer5Obj;
//		rightSpacer5Obj = orxObject_CreateFromConfig("HUDRightSpacer5Obj");
//		hudRepo->saveToRepo(rightSpacer5Obj, pos);
//		orxObject_SetPosition(rightSpacer5Obj, &pos);
//		pos.fY += 5;
//	}

	orxOBJECT *rightDeviderObj;
	rightDeviderObj = orxObject_CreateFromConfig("HUDRightDeviderObj");
	hudRepo->saveToRepo(rightDeviderObj, pos);
	orxObject_SetPosition(rightDeviderObj, &pos);
	pos.fY += 7;

//	for (int i = 0; i < 1; ++i)
//	{
//		orxOBJECT *rightSpacer5Obj;
//		rightSpacer5Obj = orxObject_CreateFromConfig("HUDRightSpacer5Obj");
//		hudRepo->saveToRepo(rightSpacer5Obj, pos);
//		orxObject_SetPosition(rightSpacer5Obj, &pos);
//		pos.fY += 5;
//	}

	orxOBJECT *rightDisplayBigObj;
	rightDisplayBigObj = orxObject_CreateFromConfig("HUDRightDisplayBigObj");
	hudRepo->saveToRepo(rightDisplayBigObj, pos);
	orxObject_SetPosition(rightDisplayBigObj, &pos);
	pos.fY += 368;

	pos.fY = edgePos - 3;
	orxOBJECT *rightBottomEdgeObj;
	rightBottomEdgeObj = orxObject_CreateFromConfig("HUDRightBottomEdgeObj");
	hudRepo->saveToRepo(rightBottomEdgeObj, pos);
	orxObject_SetPosition(rightBottomEdgeObj, &pos);

	//// BUTTONS ////

	orxVECTOR endTurnButtonPos;
	endTurnButtonPos.fX = bottomPos + 10;
	endTurnButtonPos.fY = edgePos + 10;
	endTurnButtonPos.fZ = 0.1;
	Button endTurnButton = Button(endTurnButtonPos,
								  string("HUDButtonEndTurnObj"),
								  string("HUDButtonEndTurnHlightObj"),
								  END_TURN);
	// TODO: if
	hudGFXI->clickButton(endTurnButton.getButtonId());
}
