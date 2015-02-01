
#ifndef OBJECTREPOS_HPP_
#define OBJECTREPOS_HPP_

#include <GFX/OrxGFX/OrxTypes.hpp>

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

void saveToMapObjectRepo(MapObjectRepo* mapRepo, orxOBJECT*& hexObj,
						 orxVECTOR& pos, Coord coord, GraphicObjectType type);

#endif /* OBJECTREPOS_HPP_ */
