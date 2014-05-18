
#ifndef FIGHTER_HPP_
#define FIGHTER_HPP_

#include <string>
#include "MapElement/Ship.hpp"

namespace MapElement
{

class Fighter : public Ship
{
public:
	Fighter(std::string playerName, const int count);
	~Fighter();
};

}

#endif /* FIGHTER_HPP_ */
