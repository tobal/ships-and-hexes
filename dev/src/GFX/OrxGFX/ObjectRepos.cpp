
#include "GFX/OrxGFX/ObjectRepos.hpp"

using namespace UIGFX;

void MapObjectRepo::saveToRepo(orxOBJECT*& hexObj, orxVECTOR& pos,
							   Coord coord, MapGraphicObjectType type)
{
	MapGraphicObject obj;
	obj.obj = hexObj;
	obj.coord = coord;
	switch(type)
	{
	case BACKGOBJ:
		this->background->push_back(obj);
		break;
	case HEXAOBJ:
		this->hexes->push_back(obj);
		break;
	case BORDEROBJ:
		this->borders->push_back(obj);
		break;
	case PLANETOBJ:
		this->planets->push_back(obj);
		break;
	case ANOMALYOBJ:
		this->anomalies->push_back(obj);
		break;
	case TEXTOBJ:
		this->texts->push_back(obj);
		break;
	}
}

void HUDObjectRepo::saveToRepo(orxOBJECT*& object, orxVECTOR& pos)
{
	GraphicObject gr_obj;
	gr_obj.obj = object;
	gr_obj.pos = pos;
	this->background->push_back(gr_obj);
}

void HUDObjectRepo::saveButtonToRepo(Button* button)
{
	ButtonObject buttonObj = ButtonObject(button);
	this->buttons->push_back(buttonObj);
}
