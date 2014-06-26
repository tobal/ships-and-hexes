
#ifndef SPACEOBJECT_HPP_
#define SPACEOBJECT_HPP_

#include <string>
#include "MapElement/MapElement.hpp"

namespace MapElement
{

class SpaceObject : public MapElement
{
public:
	SpaceObject(std::string playerName) : MapElement(playerName) {}
	virtual ~SpaceObject() {}
};

}

#endif /* SPACEOBJECT_HPP_ */
