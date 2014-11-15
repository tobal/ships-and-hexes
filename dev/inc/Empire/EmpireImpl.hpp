
#ifndef EMPIREIMPL_HPP_
#define EMPIREIMPL_HPP_

#include "Empire/Empire.hpp"
#include "Empire/CommonTypes.hpp"
#include "GameMap/GameMap.hpp"
#include "Empire/Effect/EmpireEffect.hpp"
#include "MapElement/Anomaly.hpp"

namespace Empire
{

class EmpireImpl : public Empire
{
public:
	EmpireImpl();
	~EmpireImpl();
	void aggregateEmpireEffectsForPlayer(GameMap::GameMap* map, Effect::EmpireEffects* effects,
										 std::string playerName);
};

}
#endif /* EMPIREIMPL_HPP_ */
