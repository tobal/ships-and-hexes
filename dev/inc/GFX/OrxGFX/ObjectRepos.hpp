
#ifndef OBJECTREPOS_HPP_
#define OBJECTREPOS_HPP_

#include <GFX/OrxGFX/OrxTypes.hpp>

struct MapObjectRepo
{
	MapObjectRepo()
	{
		background = new MapGraphicObjects();
		hexes = new MapGraphicObjects();
		borders = new MapGraphicObjects();
		planets = new MapGraphicObjects();
		anomalies = new MapGraphicObjects();
		texts = new MapGraphicObjects();
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
	MapGraphicObjects* background;
	MapGraphicObjects* hexes;
	MapGraphicObjects* borders;
	MapGraphicObjects* planets;
	MapGraphicObjects* anomalies;
	MapGraphicObjects* texts;

	void saveToRepo(orxOBJECT*& hexObj, orxVECTOR& pos, Coord coord, MapGraphicObjectType type);
};

void saveToMapObjectRepo(MapObjectRepo* mapRepo, orxOBJECT*& hexObj,
						 orxVECTOR& pos, Coord coord, MapGraphicObjectType type);

struct HUDObjectRepo
{
	HUDObjectRepo()
	{
		background = new GraphicObjects();
	}
	~HUDObjectRepo()
	{
		delete background;
	}
	GraphicObjects* background;

	void saveToRepo(orxOBJECT*& obj, orxVECTOR& pos);
};

#endif /* OBJECTREPOS_HPP_ */
