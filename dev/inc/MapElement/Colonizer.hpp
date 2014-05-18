
#ifndef COLONIZER_HPP_
#define COLONIZER_HPP_

#include <string>
#include "MapElement/Ship.hpp"

namespace MapElement
{

class Colonizer : public Ship
{
public:
	Colonizer(std::string playerName, const int count);
	~Colonizer();
};

}

#endif /* COLONIZER_HPP_ */
