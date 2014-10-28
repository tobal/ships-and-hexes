
#ifndef COLONIZER_HPP_
#define COLONIZER_HPP_

#include <string>
#include "MapElement/Ship.hpp"

namespace MapElement
{

class Colonizer : public Ship
{
public:
	Colonizer(const int count);
	~Colonizer();
	void merge(Colonizer* otherFighter);
};

}

#endif /* COLONIZER_HPP_ */
