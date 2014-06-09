
#ifndef MAPELEMENT_HPP_
#define MAPELEMENT_HPP_

#include <string>
#include "Empire/Effect/Effect.hpp"

namespace MapElement
{

class MapElement
{
protected:
	std::string playerName;
	MapElement(std::string playerName) : playerName(playerName) {}
	virtual ~MapElement() {}

public:
	virtual Empire::Effect::Effects getEffects() {}
	std::string getPlayerName() const { return playerName; }
};

}

#endif /* MAPELEMENT_HPP_ */
