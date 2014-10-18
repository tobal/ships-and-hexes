
#include "orx.h"
#include "GameMap/GameMapGenerator.hpp"
#include "MapElement/Planet.hpp"
#include "MapElement/Anomaly.hpp"
#include <sstream>

using namespace GameMap;
using namespace MapElement;

orxSTATUS orxFASTCALL Init()
{
  orxConfig_Load("cfg/mainConf.ini");

  orxViewport_CreateFromConfig("Viewport");

  float x0 = -370.0;
  float y0 = -270.0;
//  for (int i = 0; i < 10; ++i) {
//	for (int j = 0; j < 10; ++j) {
//		orxVECTOR pos;
//		pos.fX = x0 + i * 50;
//		if(j % 2 > 0)
//			pos.fX += 25.0;
//		pos.fY = y0 + j * 43;
//		pos.fZ = 0.0;
//
//		orxOBJECT *hex;
//		hex = orxObject_CreateFromConfig("HexaObj");
//		orxObject_SetPosition(hex, &pos);
//
//		orxVECTOR scale;
//		orxVECTOR *help;
//		help = orxObject_GetScale(hex, &scale);
//		help = orxVector_Mulf(&scale, help, orx2F(0.5f));
//		orxObject_SetScale(hex, help);
//	}
//  }


  GameMapGenerator* generator;
  generator = new GameMapGenerator();
  int density = 10;
  GameMap::GameMap* map = generator->generateMap(Coord(15, 12), density);
	Coord dimensions = map->getDimensions();
	for (int x = 0; x < dimensions.x; ++x)
	{
		for (int y = 0; y < dimensions.y; ++y)
		{
			orxVECTOR pos;
			pos.fX = x0 + x * 50;
			if(y % 2 > 0)
				pos.fX += 25.0;
			pos.fY = y0 + y * 43;
			pos.fZ = 0.0;

			orxOBJECT *hexObj;
			hexObj = orxObject_CreateFromConfig("HexaObj");
			orxObject_SetPosition(hexObj, &pos);
			Hex* hex = map->getHexOnCoord(Coord(x, y));
			if(hex->hasSpaceObject())
			{
				if(hex->getSpaceObjectType() == PLANET)
				{
					Planet* pl = dynamic_cast<Planet*>(hex->getSpaceObject());
					orxOBJECT *planetObj;
					switch(pl->getPlanetType())
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
					orxObject_SetPosition(planetObj, &pos);

					float scaleValue = 0.9;
					switch(pl->getPlanetSize())
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
				}
				if(hex->getSpaceObjectType() == ANOMALY)
				{
					std::ostringstream anomalyObjName;
					anomalyObjName << "Anomaly";

					Anomaly* anom = dynamic_cast<Anomaly*>(hex->getSpaceObject());
					switch(anom->getType())
					{
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
					switch(anom->getSize())
					{
					case LITTLE:
						anomalyObjName << "Little";
						break;
					case BIG:
						anomalyObjName << "Big";
						break;
					}
					anomalyObjName << "Obj";

					orxOBJECT *anomalyObj;
					anomalyObj = orxObject_CreateFromConfig(anomalyObjName.str().c_str());
					orxObject_SetPosition(anomalyObj, &pos);
				}
			}
		}
	}


  /* Gets current parent position */
//  orxVECTOR vParentPosition;
//  orxObject_GetWorldPosition(h1, &vParentPosition);
//  orxLOG("%f, %f, %f", vParentPosition.fX, vParentPosition.fY, vParentPosition.fZ);
//  h3 = orxObject_CreateFromConfig("HexaObj");
  std::ostringstream bg;
  bg << "BackgroundObj" << ((rand() % 3) + 1);
  orxObject_CreateFromConfig(bg.str().c_str());
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
