
#ifndef EFFECTIVENESSBONUS_HPP_
#define EFFECTIVENESSBONUS_HPP_

#include "Empire/Effect/BattleEffect.hpp"

namespace Empire
{
namespace Effect
{

class EffectivenessBonus : public BattleEffect
{
private:
	int bonusPercent;
public:
	EffectivenessBonus(int bonusPercent);
	~EffectivenessBonus();
};

} /* namespace Effect */
} /* namespace Empire */

#endif /* EFFECTIVENESSBONUS_HPP_ */
