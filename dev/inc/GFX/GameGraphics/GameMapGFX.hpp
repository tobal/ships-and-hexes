
#ifndef GAMEMAPGFX_HPP_
#define GAMEMAPGFX_HPP_

#include "orx.h"
#include "GameMap/GameMap.hpp"
#include "GameMap/Hex.hpp"
#include "MapElement/Planet.hpp"
#include "MapElement/Anomaly.hpp"
#include "GFX/OrxGFX/ObjectRepos.hpp"
#include <sstream>

namespace GameGraphics
{

class GameMapGFX
{
private:
	MapObjectRepo* mapRepo;

	orxVECTOR getPositionOfCoords(float x0, int& x, int& y, float y0);
	void drawBorders(GameMap::GameMap* map, float x0, float y0, int borderThickness);
	void drawHexMap(GameMap::GameMap* map, float x0, float y0);
	void drawMapBackground();
	void translateObjectWithDelta(orxOBJECT* obj, float factor, orxVECTOR* delta);
public:
	GameMapGFX();
	~GameMapGFX();
	void updateMap(orxVIEWPORT* viewport, orxVECTOR* delta);
	void drawMap(GameMap::GameMap* gameMap);
};

}

#endif /* GAMEMAPGFX_HPP_ */
