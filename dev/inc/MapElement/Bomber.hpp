
#ifndef BOMBER_HPP_
#define BOMBER_HPP_

#include <string>
#include "MapElement/Ship.hpp"

namespace MapElement
{

class Bomber : public Ship
{
public:
	Bomber(std::string playerName, const int count);
	~Bomber();
	void merge(Bomber* otherFighter);
};

}

#endif /* BOMBER_HPP_ */
