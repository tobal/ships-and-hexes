
#include "GFX/GameGraphics/GameMapGFX.hpp"

using namespace GameGraphics;
using namespace GameMap;
using namespace MapElement;

GameMapGFX::GameMapGFX()
{
	mapRepo = new MapObjectRepo();
}

GameMapGFX::~GameMapGFX()
{
	delete mapRepo;
}

orxVECTOR GameMapGFX::getPositionOfCoords(float x0, int& x, int& y, float y0)
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

void GameMapGFX::drawBorders(GameMap::GameMap* map, float x0, float y0, int borderThickness)
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
				mapRepo->saveToRepo(fowObj, pos, Coord(x, y), BORDEROBJ);
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

void GameMapGFX::drawHexMap(GameMap::GameMap* map, float x0, float y0)
{
	Coord dimensions = map->getDimensions();

	for (int x = 0; x < dimensions.x; ++x)
	{
		for (int y = 0; y < dimensions.y; ++y)
		{
			orxVECTOR pos = getPositionOfCoords(x0, x, y, y0);

			orxOBJECT *hexObj;
			hexObj = orxObject_CreateFromConfig("HexaObj");
			mapRepo->saveToRepo(hexObj, pos, Coord(x, y), HEXAOBJ);
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
					mapRepo->saveToRepo(planetObj, pos, Coord(x, y), PLANETOBJ);
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
						mapRepo->saveToRepo(textObj, pos, Coord(x, y), TEXTOBJ);
					}
					if (hex->getSpaceObject()->getPlayerName() == "player2")
					{
						orxOBJECT *textObj;
						textObj = orxObject_CreateFromConfig("TextObj");
						orxObject_SetTextString(textObj, "player2");
						orxObject_SetPosition(textObj, &pos);
						mapRepo->saveToRepo(textObj, pos, Coord(x, y), TEXTOBJ);
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
					mapRepo->saveToRepo(anomalyObj, pos, Coord(x, y), ANOMALYOBJ);
				}
			}
		}
	}
}

void GameMapGFX::drawMapBackground()
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
			mapRepo->saveToRepo(backgObj, pos, Coord(0, 0), BACKGOBJ);
		}
	}
}

void GameMapGFX::drawMap(GameMap::GameMap* gameMap)
{
	float x0 = -600.0;
	float y0 = -320.0;

	int borderThickness = 10;
	drawBorders(gameMap, x0 - borderThickness * 50, y0 - borderThickness * 43, borderThickness);
	drawHexMap(gameMap, x0, y0);
	drawMapBackground();
}

void GameMapGFX::translateObjectWithDelta(orxOBJECT* obj, float factor, orxVECTOR* delta)
{
	orxVECTOR pos;
	orxObject_GetPosition(obj, &pos);
	orxVECTOR normalDelta = orxVECTOR_0;
	orxVector_Mulf(&normalDelta, delta, orx2F(factor));
	orxVector_Add(&pos, &pos, &normalDelta);
	orxObject_SetPosition(obj, &pos);
}

void GameMapGFX::updateMap(orxVIEWPORT* viewport, orxVECTOR* delta)
{
	float translateFactor = 0.65f;
	for (MapGraphicObjects::iterator gObj = mapRepo->hexes->begin(); gObj != mapRepo->hexes->end(); ++gObj)
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
			float fadeFactor = 0.0f;
			float fadeRadius = 400.0f;
			if(distance < fadeRadius)
			{
				fadeFactor = 1.0f;
				if(distance != 0.0f)
				{
					fadeFactor =  1.0f - distance / fadeRadius;
				}
			}
			orxColor_SetAlpha(&color, orx2F(fadeFactor));
		}

		orxObject_SetColor(obj, &color);

		translateObjectWithDelta(obj, translateFactor, delta);
	}
	for (MapGraphicObjects::iterator gObj = mapRepo->borders->begin(); gObj != mapRepo->borders->end(); ++gObj)
	{
		orxOBJECT* obj = (*gObj).obj;
		translateObjectWithDelta(obj, translateFactor, delta);
	}
	for (MapGraphicObjects::iterator gObj = mapRepo->planets->begin(); gObj != mapRepo->planets->end(); ++gObj)
	{
		orxOBJECT* obj = (*gObj).obj;
		translateObjectWithDelta(obj, translateFactor, delta);
	}
	for (MapGraphicObjects::iterator gObj = mapRepo->anomalies->begin(); gObj != mapRepo->anomalies->end(); ++gObj)
	{
		orxOBJECT* obj = (*gObj).obj;
		translateObjectWithDelta(obj, translateFactor, delta);
	}
	for (MapGraphicObjects::iterator gObj = mapRepo->texts->begin(); gObj != mapRepo->texts->end(); ++gObj)
	{
		orxOBJECT* obj = (*gObj).obj;
		translateObjectWithDelta(obj, translateFactor, delta);
	}
	for (MapGraphicObjects::iterator gObj = mapRepo->background->begin(); gObj != mapRepo->background->end(); ++gObj)
	{
		orxOBJECT* obj = (*gObj).obj;
		translateObjectWithDelta(obj, 1.0f, delta);
	}
}
