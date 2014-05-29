
#ifndef POPULATIONBONUS_HPP_
#define POPULATIONBONUS_HPP_

#include "Empire/Effect/EmpireEffect.hpp"

namespace Empire
{
namespace Effect
{

class PopulationBonus : public EmpireEffect
{
public:
	PopulationBonus();
	~PopulationBonus();
	void setEffectByShipControl(const int control);
};

} /* namespace Effect */
} /* namespace Empire */

#endif /* POPULATIONBONUS_HPP_ */
