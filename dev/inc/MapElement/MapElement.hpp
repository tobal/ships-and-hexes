
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

public:
	virtual ~MapElement() {}
	virtual Empire::Effect::Effects getEffects() {}
	std::string getPlayerName() const { return playerName; }
	void setPlayerName(const std::string playerName) { this->playerName = playerName; }
};

}

#endif /* MAPELEMENT_HPP_ */
