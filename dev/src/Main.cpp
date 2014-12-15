
#include "Main.hpp"

using namespace GameMap;
using namespace MapElement;
using namespace Empire::Effect;
using namespace GameConfig;
using namespace std;

GameMapImpl* generateMap()
{
	GameMapGenerator* generator;
	generator = new GameMapGenerator();
	Player player1 = Player("player1", RED, false);
	Player player2 = Player("player2", YELLOW, true);
	vector<int> picked = vector<int>();
	picked.push_back(0);
	picked.push_back(2);
	picked.push_back(3);
	picked.push_back(17);
	player1.getPlayerConfig()->pickTraits(picked);
	Players players = Players();
	players.push_back(player1);
	players.push_back(player2);
	GameMapImpl* map = dynamic_cast<GameMapImpl*>(generator->generateMap(
			Coord(15, 12), 40, players));
	return map;
}

void drawHexMap(GameMapImpl* map, float x0, float y0)
{
	Coord dimensions = map->getDimensions();
	for (int x = 0; x < dimensions.x; ++x)
	{
		for (int y = 0; y < dimensions.y; ++y)
		{
			orxVECTOR pos;
			pos.fX = x0 + x * 50;
			if (y % 2 > 0)
				pos.fX += 25.0;
			pos.fY = y0 + y * 43;
			pos.fZ = 0.0;

			orxOBJECT *hexObj;
			hexObj = orxObject_CreateFromConfig("HexaObj");
			orxObject_SetPosition(hexObj, &pos);
			Hex* hex = map->getHexOnCoord(Coord(x, y));
			if (hex->hasSpaceObject())
			{
				if (hex->getSpaceObjectType() == PLANET)
				{
					Planet* pl = dynamic_cast<Planet*>(hex->getSpaceObject());
					orxOBJECT *planetObj;
					switch (pl->getPlanetType())
					{
					case WATER:
						planetObj = orxObject_CreateFromConfig(
								"PlanetWaterObj");
						break;
					case DESERT:
						planetObj = orxObject_CreateFromConfig(
								"PlanetDesertObj");
						break;
					case LAVA:
						planetObj = orxObject_CreateFromConfig("PlanetLavaObj");
						break;
					}
					orxObject_SetPosition(planetObj, &pos);

					float scaleValue = 0.9;
					switch (pl->getPlanetSize())
					{
					case SMALL:
						scaleValue = 0.7;
						break;
					case MEDIUM:
						scaleValue = 0.5;
						break;
					}

					orxVECTOR scale;
					orxVECTOR *help;
					help = orxObject_GetScale(planetObj, &scale);
					help = orxVector_Mulf(&scale, help, orx2F(scaleValue));
					orxObject_SetScale(planetObj, help);

					if (hex->getSpaceObject()->getPlayerName() == "player1")
					{
						orxOBJECT *textObj;
						textObj = orxObject_CreateFromConfig("TextObj");
						orxObject_SetTextString(textObj, "player1");
						orxObject_SetPosition(textObj, &pos);
					}
					if (hex->getSpaceObject()->getPlayerName() == "player2")
					{
						orxOBJECT *textObj;
						textObj = orxObject_CreateFromConfig("TextObj");
						orxObject_SetTextString(textObj, "player2");
						orxObject_SetPosition(textObj, &pos);
					}
				}
				if (hex->getSpaceObjectType() == ANOMALY) {
					std::ostringstream anomalyObjName;
					anomalyObjName << "Anomaly";

					Anomaly* anom =
							dynamic_cast<Anomaly*>(hex->getSpaceObject());
					switch (anom->getType()) {
					case ASTEROIDFIELD:
						anomalyObjName << "Asteroid";
						break;
					case GASCLOUD:
						anomalyObjName << "Cloud";
						break;
					case ALIENWRECK:
						anomalyObjName << "Wreck";
						break;
					}
					switch (anom->getSize()) {
					case LITTLE:
						anomalyObjName << "Little";
						break;
					case BIG:
						anomalyObjName << "Big";
						break;
					}
					anomalyObjName << "Obj";

					orxOBJECT *anomalyObj;
					anomalyObj = orxObject_CreateFromConfig(
							anomalyObjName.str().c_str());
					orxObject_SetPosition(anomalyObj, &pos);
				}
			}
		}
	}
}

void drawMapBackground() {
	std::ostringstream bg;
	bg << "BackgroundObj" << ((rand() % 3) + 1);
	orxObject_CreateFromConfig(bg.str().c_str());
}

void drawMap() {
	float x0 = -370.0;
	float y0 = -270.0;
	GameMapImpl* map = generateMap();
	drawHexMap(map, x0, y0);
	drawMapBackground();
}

// TODO
orxVIEWPORT *viewport;
orxOBJECT *mouseCursor;

void orxFASTCALL Update(const orxCLOCK_INFO *_pstClockInfo, void *_pstContext)
{
//  orxVECTOR vScale, vPosition;
//
//  /* Is rotate left input active ? */
//  if(orxInput_IsActive("RotateLeft"))
//  {
//    /* Rotates Parent object CCW */
//    orxObject_SetRotation(pstParentObject, orxObject_GetRotation(pstParentObject) - orxMATH_KF_PI * _pstClockInfo->fDT);
//  }
//  /* Is rotate right input active? */
//  if(orxInput_IsActive("RotateRight"))
//  {
//    /* Rotates Parent object CW */
//    orxObject_SetRotation(pstParentObject, orxObject_GetRotation(pstParentObject) + orxMATH_KF_PI * _pstClockInfo->fDT);
//  }
//
//  /* Is scale up input active? */
//  if(orxInput_IsActive("ScaleUp"))
//  {
//    /* Scales up the Parent object */
//    orxObject_SetScale(pstParentObject, orxVector_Mulf(&vScale, orxObject_GetScale(pstParentObject, &vScale), orx2F(1.02f)));
//  }
//  /* Is scale down input active? */
//  if(orxInput_IsActive("ScaleDown"))
//  {
//    /* Scales down the Parent object */
//    orxObject_SetScale(pstParentObject, orxVector_Mulf(&vScale, orxObject_GetScale(pstParentObject, &vScale), orx2F(0.98f)));
//  }

	orxVECTOR vPosition;
	/* Is mouse in viewport? */
	if(orxRender_GetWorldPosition(orxMouse_GetPosition(&vPosition), viewport, &vPosition))
	{
		orxVECTOR vParentPosition;
		orxObject_GetWorldPosition(mouseCursor, &vParentPosition);
		vPosition.fZ = vParentPosition.fZ;
		orxObject_SetPosition(mouseCursor, &vPosition);
	}
}

orxSTATUS orxFASTCALL Init()
{
	orxConfig_Load("cfg/mainConf.ini");
	viewport = orxViewport_CreateFromConfig("Viewport");

	mouseCursor = orxObject_CreateFromConfig("CursorObj");
	drawMap();


	orxINPUT_TYPE   eType;
	orxENUM         eID;
	const orxSTRING zInputUp;
	const orxSTRING zInputDown;
	const orxSTRING zInputLeft;
	const orxSTRING zInputRight;

	orxInput_GetBinding("Up", 0, &eType, &eID);
	zInputUp = orxInput_GetBindingName(eType, eID);

	orxInput_GetBinding("Down", 0, &eType, &eID);
	zInputDown = orxInput_GetBindingName(eType, eID);

	orxInput_GetBinding("Left", 0, &eType, &eID);
	zInputLeft = orxInput_GetBindingName(eType, eID);

	orxInput_GetBinding("Right", 0, &eType, &eID);
	zInputRight = orxInput_GetBindingName(eType, eID);


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
}

int main(int argc, char **argv)
{
	orx_Execute(argc, argv, Init, Run, Exit);
	return EXIT_SUCCESS;
}
