
#ifndef ORXTYPES_HPP_
#define ORXTYPES_HPP_

#include "orx.h"
#include <vector>
#include "Empire/CommonTypes.hpp"
#include "GFX/UIGFX/Button.hpp"

struct MapGraphicObject
{
	orxOBJECT* obj;
	Coord coord;
};

enum MapGraphicObjectType
{
	BACKGOBJ,
	HEXAOBJ,
	BORDEROBJ,
	PLANETOBJ,
	ANOMALYOBJ,
	TEXTOBJ
};

typedef std::vector<MapGraphicObject> MapGraphicObjects;

struct GraphicObject
{
	orxOBJECT* obj;
	orxVECTOR pos;
};

typedef std::vector<GraphicObject> GraphicObjects;


struct ButtonObject
{
	UIGFX::Button* button;
	GraphicObject gfx;
	GraphicObject gfxHighl;
	ButtonObject(UIGFX::Button* button)
	{
		this->button = button;
		this->gfx.pos = this->button->getButtonPos();
		this->gfx.obj = orxObject_CreateFromConfig(this->button->getButtonPic().c_str());
		this->gfxHighl.pos = this->button->getButtonPos();
		this->gfxHighl.obj = orxObject_CreateFromConfig(this->button->getButtonHighlightPic().c_str());
	}
};

typedef std::vector<ButtonObject> ButtonObjects;
#endif /* ORXTYPES_HPP_ */
