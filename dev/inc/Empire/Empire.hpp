
#ifndef EMPIRE_HPP_
#define EMPIRE_HPP_

#include "GameMap/GameMap.hpp"
#include "Empire/Effect/EmpireEffect.hpp"

namespace Empire
{

class Empire
{
public:
	Empire() {}
	virtual ~Empire() {}
	virtual void aggregateEmpireEffectsForPlayer(GameMap::GameMap* map, Effect::EmpireEffects* effects,
												 std::string playerName) {}
};

}

#endif /* EMPIRE_HPP_ */
