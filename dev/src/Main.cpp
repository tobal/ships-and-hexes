
#include "Main.hpp"

using namespace GameMap;
using namespace MapElement;
using namespace Empire::Effect;
using namespace GameConfig;
using namespace std;

// TODO put this elsewhere
struct GraphicObject
{
	orxOBJECT* obj;
	Coord coord;
};

enum GraphicObjectType
{
	BACKGOBJ,
	HEXAOBJ,
	BORDEROBJ,
	PLANETOBJ,
	ANOMALYOBJ,
	TEXTOBJ
};

typedef vector<GraphicObject> GraphicObjects;

struct MapObjectRepo
{
	MapObjectRepo()
	{
		background = new GraphicObjects();
		hexes = new GraphicObjects();
		borders = new GraphicObjects();
		planets = new GraphicObjects();
		anomalies = new GraphicObjects();
		texts = new GraphicObjects();
	}
	~MapObjectRepo()
	{
		delete background;
		delete hexes;
		delete borders;
		delete planets;
		delete anomalies;
		delete texts;
	}
	GraphicObjects* background;
	GraphicObjects* hexes;
	GraphicObjects* borders;
	GraphicObjects* planets;
	GraphicObjects* anomalies;
	GraphicObjects* texts;
};


// TODO: put global state somewhere

orxVIEWPORT* viewport;
orxOBJECT* mouseCursor;
GameMap::GameMap* gameMap = NULL;
MapObjectRepo* mapRepo;
orxVECTOR translation = orxVECTOR_0;
orxVECTOR delta = orxVECTOR_0;

bool mbleftFlag = false;


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
			Coord(25, 20), 40, players));
	return map;
}

void saveToObjectRepo(orxOBJECT*& hexObj, orxVECTOR& pos, Coord coord, GraphicObjectType type)
{
	GraphicObject obj;
	obj.obj = hexObj;
	obj.coord = coord;
	switch(type)
	{
	case BACKGOBJ:
		mapRepo->background->push_back(obj);
		break;
	case HEXAOBJ:
		mapRepo->hexes->push_back(obj);
		break;
	case BORDEROBJ:
		mapRepo->borders->push_back(obj);
		break;
	case PLANETOBJ:
		mapRepo->planets->push_back(obj);
		break;
	case ANOMALYOBJ:
		mapRepo->anomalies->push_back(obj);
		break;
	case TEXTOBJ:
		mapRepo->texts->push_back(obj);
		break;
	}
}

orxVECTOR getPositionOfCoords(float x0, int& x, int& y, float y0)
{
	orxVECTOR pos;
	pos.fX = x0 + x * 50;
	if (y % 2 > 0)
	{
		pos.fX += 25.0;
	}
	pos.fY = y0 + y * 43;
	pos.fZ = 0.0;
	return pos;
}

void drawBorders(GameMap::GameMap* map, float x0, float y0, int borderThickness)
{
	Coord dimensions = map->getDimensions();

	for (int x = 0; x < dimensions.x + borderThickness * 2; ++x)
	{
		for (int y = 0; y < dimensions.y + borderThickness * 2; ++y)
		{
			if((x < borderThickness || x >= dimensions.x + borderThickness) ||
			   (y < borderThickness || y >= dimensions.y + borderThickness))
			{
				orxVECTOR pos = getPositionOfCoords(x0, x, y, y0);

				orxOBJECT* fowObj;
				fowObj = orxObject_CreateFromConfig("FogOfWarObj");
				saveToObjectRepo(fowObj, pos, Coord(x, y), BORDEROBJ);
				orxObject_SetPosition(fowObj, &pos);

				orxCOLOR color;
				orxVECTOR colorVec = orxVECTOR_BLACK;
				orxColor_Set(&color, &colorVec, orxFLOAT_1);
				orxColor_SetAlpha(&color, orx2F(0.5));
				orxObject_SetColor(fowObj, &color);
			}
		}
	}
}

void drawHexMap(GameMap::GameMap* map, float x0, float y0)
{
	Coord dimensions = map->getDimensions();

	for (int x = 0; x < dimensions.x; ++x)
	{
		for (int y = 0; y < dimensions.y; ++y)
		{
			orxVECTOR pos = getPositionOfCoords(x0, x, y, y0);

			orxOBJECT *hexObj;
			hexObj = orxObject_CreateFromConfig("HexaObj");
			saveToObjectRepo(hexObj, pos, Coord(x, y), HEXAOBJ);
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
						planetObj = orxObject_CreateFromConfig("PlanetWaterObj");
						break;
					case DESERT:
						planetObj = orxObject_CreateFromConfig("PlanetDesertObj");
						break;
					case LAVA:
						planetObj = orxObject_CreateFromConfig("PlanetLavaObj");
						break;
					}
					saveToObjectRepo(planetObj, pos, Coord(x, y), PLANETOBJ);
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
						saveToObjectRepo(textObj, pos, Coord(x, y), TEXTOBJ);
					}
					if (hex->getSpaceObject()->getPlayerName() == "player2")
					{
						orxOBJECT *textObj;
						textObj = orxObject_CreateFromConfig("TextObj");
						orxObject_SetTextString(textObj, "player2");
						orxObject_SetPosition(textObj, &pos);
						saveToObjectRepo(textObj, pos, Coord(x, y), TEXTOBJ);
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

					orxOBJECT* anomalyObj;
					anomalyObj = orxObject_CreateFromConfig(
							anomalyObjName.str().c_str());
					orxObject_SetPosition(anomalyObj, &pos);
					saveToObjectRepo(anomalyObj, pos, Coord(x, y), ANOMALYOBJ);
				}
			}
		}
	}
}

void drawMapBackground()
{
	std::ostringstream bg;
	bg << "BackgroundObj" << ((rand() % 3) + 1);
	for (float i = -2048.0; i < 2048.0; i += 1024.0)
	{
		for (float j = -2048.0; j < 2048.0; j += 1024.0)
		{
			orxOBJECT* backgObj;
			backgObj = orxObject_CreateFromConfig(bg.str().c_str());
			orxVECTOR pos = orxVECTOR_0;
			orxVector_Set(&pos, orx2F(i), orx2F(j), orx2F(0.0));
			orxObject_SetPosition(backgObj, &pos);
			saveToObjectRepo(backgObj, pos, Coord(0, 0), BACKGOBJ);
		}
	}
}

void drawMap()
{
	float x0 = -600.0;
	float y0 = -320.0;
	if(gameMap == NULL)
	{
		gameMap = generateMap();
	}

	int borderThickness = 10;
	drawBorders(gameMap, x0 - borderThickness * 50, y0 - borderThickness * 43, borderThickness);
	drawHexMap(gameMap, x0, y0);
	drawMapBackground();
}

void translateObjectWithDelta(orxOBJECT* obj, float factor)
{
	orxVECTOR pos;
	orxObject_GetPosition(obj, &pos);
	orxVECTOR normalDelta = orxVECTOR_0;
	orxVector_Mulf(&normalDelta, &delta, orx2F(factor));
	orxVector_Add(&pos, &pos, &normalDelta);
//	orxLOG("delta: %f, %f; normalDelta: %f, %f; pos: %f, %f",
//			delta.fX, delta.fY, normalDelta.fX, normalDelta.fY, pos.fX, pos.fY);
	orxObject_SetPosition(obj, &pos);
}

void updateMap()
{
	float translateFactor = 0.65f;
	for (GraphicObjects::iterator gObj = mapRepo->hexes->begin(); gObj != mapRepo->hexes->end(); ++gObj)
	{
		orxOBJECT* obj = (*gObj).obj;
		orxCOLOR color;
		orxVECTOR colorVec = orxVECTOR_WHITE;
		orxColor_Set(&color, &colorVec, orxFLOAT_1);

		orxVECTOR mousePos;
		if(orxRender_GetWorldPosition(orxMouse_GetPosition(&mousePos), viewport, &mousePos))
		{
			orxVECTOR objPos;
			orxObject_GetPosition(obj, &objPos);
			orxFLOAT distance = orxVector_GetDistance(&objPos, &mousePos);
			float fadeFactor = 1.0f;
			float fadeRadius = 400.0f;
			if(distance < fadeRadius)
			{
				fadeFactor = 0.0f;
				if(distance != 0.0f)
				{
					fadeFactor = (1.0f / fadeRadius) * distance;
				}
			}
			orxColor_SetAlpha(&color, orx2F(fadeFactor));
		}

		orxObject_SetColor(obj, &color);

		translateObjectWithDelta(obj, translateFactor);
	}
	for (GraphicObjects::iterator gObj = mapRepo->borders->begin(); gObj != mapRepo->borders->end(); ++gObj)
	{
		orxOBJECT* obj = (*gObj).obj;
		translateObjectWithDelta(obj, translateFactor);
	}
	for (GraphicObjects::iterator gObj = mapRepo->planets->begin(); gObj != mapRepo->planets->end(); ++gObj)
	{
		orxOBJECT* obj = (*gObj).obj;
		translateObjectWithDelta(obj, translateFactor);
	}
	for (GraphicObjects::iterator gObj = mapRepo->anomalies->begin(); gObj != mapRepo->anomalies->end(); ++gObj)
	{
		orxOBJECT* obj = (*gObj).obj;
		translateObjectWithDelta(obj, translateFactor);
	}
	for (GraphicObjects::iterator gObj = mapRepo->texts->begin(); gObj != mapRepo->texts->end(); ++gObj)
	{
		orxOBJECT* obj = (*gObj).obj;
		translateObjectWithDelta(obj, translateFactor);
	}
	for (GraphicObjects::iterator gObj = mapRepo->background->begin(); gObj != mapRepo->background->end(); ++gObj)
	{
		orxOBJECT* obj = (*gObj).obj;
		translateObjectWithDelta(obj, 1.0f);
	}
}

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

	orxVECTOR mousePos;
	if(orxRender_GetWorldPosition(orxMouse_GetPosition(&mousePos), viewport, &mousePos))
	{
		orxVECTOR vParentPosition;
		orxObject_GetWorldPosition(mouseCursor, &vParentPosition);
		mousePos.fZ = vParentPosition.fZ;
		orxObject_SetPosition(mouseCursor, &mousePos);

		if(orxMouse_IsButtonPressed(orxMOUSE_BUTTON_LEFT))
		{
			// dragging
			orxMouse_GetMoveDelta(&delta);
//			orxLOG("delta: %f, %f; trans: %f, %f", delta.fX, delta.fY, translation.fX, translation.fY);
			orxVector_Add(&translation, &translation, &delta);
//			orxLOG("delta: %f, %f; trans: %f, %f", delta.fX, delta.fY, translation.fX, translation.fY);

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

	updateMap();
}

orxSTATUS orxFASTCALL Init()
{
	orxConfig_Load("cfg/mainConf.ini");
	viewport = orxViewport_CreateFromConfig("Viewport");

	mouseCursor = orxObject_CreateFromConfig("CursorObj");

	mapRepo = new MapObjectRepo();
	drawMap();

//	orxINPUT_TYPE   eType;
//	orxENUM         eID;
//	const orxSTRING zInputUp;
//	const orxSTRING zInputDown;
//	const orxSTRING zInputLeft;
//	const orxSTRING zInputRight;
//
//	orxInput_GetBinding("Up", 0, &eType, &eID);
//	zInputUp = orxInput_GetBindingName(eType, eID);
//
//	orxInput_GetBinding("Down", 0, &eType, &eID);
//	zInputDown = orxInput_GetBindingName(eType, eID);
//
//	orxInput_GetBinding("Left", 0, &eType, &eID);
//	zInputLeft = orxInput_GetBindingName(eType, eID);
//
//	orxInput_GetBinding("Right", 0, &eType, &eID);
//	zInputRight = orxInput_GetBindingName(eType, eID);


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
	delete mapRepo;
}

int main(int argc, char **argv)
{
	orx_Execute(argc, argv, Init, Run, Exit);
	return EXIT_SUCCESS;
}
