
#ifndef ORXTYPES_HPP_
#define ORXTYPES_HPP_

#include "orx.h"
#include <vector>
#include "Empire/CommonTypes.hpp"

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

#endif /* ORXTYPES_HPP_ */
