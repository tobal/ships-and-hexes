
#ifndef FIGHTER_HPP_
#define FIGHTER_HPP_

#include <string>
#include "MapElement/Ship.hpp"

namespace MapElement
{

class Fighter : public Ship
{
public:
	Fighter(const int count);
	~Fighter();
	void merge(Fighter* otherFighter);
};

}

#endif /* FIGHTER_HPP_ */
