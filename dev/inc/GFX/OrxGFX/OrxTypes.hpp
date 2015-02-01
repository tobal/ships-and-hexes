
#ifndef ORXTYPES_HPP_
#define ORXTYPES_HPP_

#include "orx.h"
#include <vector>
#include "Empire/CommonTypes.hpp"

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

typedef std::vector<GraphicObject> GraphicObjects;

#endif /* ORXTYPES_HPP_ */
