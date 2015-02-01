
#include "GFX/OrxGFX/ObjectRepos.hpp"

void saveToMapObjectRepo(MapObjectRepo* mapRepo, orxOBJECT*& hexObj,
						 orxVECTOR& pos, Coord coord, GraphicObjectType type)
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
