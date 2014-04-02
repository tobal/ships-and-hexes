
#ifndef SHIPBONUS_HPP_
#define SHIPBONUS_HPP_

#include "Empire/Effect/BattleEffect.hpp"

namespace Empire
{
namespace Effect
{

class ShipBonus : public BattleEffect
{
private:
	int bonusPercent;
public:
	ShipBonus(int bonusPercent);
	~ShipBonus();
};

} /* namespace Effect */
} /* namespace Empire */

#endif /* SHIPBONUS_HPP_ */
