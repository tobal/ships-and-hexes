
#ifndef MAPELEMENTFACTORY_HPP_
#define MAPELEMENTFACTORY_HPP_

#include <string>
#include "MapElement/Fighter.hpp"

namespace MapElement
{

class MapElementFactory
{
private:
	std::string playerName;

public:
	MapElementFactory(std::string playerName);
	~MapElementFactory();
	Fighter* createFighter(const int count) const;
};

}

#endif /* MAPELEMENTFACTORY_HPP_ */
