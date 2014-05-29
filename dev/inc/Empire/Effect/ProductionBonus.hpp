
#ifndef PRODUCTIONBONUS_HPP_
#define PRODUCTIONBONUS_HPP_

#include "Empire/Effect/EmpireEffect.hpp"

namespace Empire
{
namespace Effect
{

class ProductionBonus : public EmpireEffect
{
public:
	ProductionBonus();
	~ProductionBonus();
	void setEffectByShipControl(const int control);
};

} /* namespace Effect */
} /* namespace Empire */

#endif /* PRODUCTIONBONUS_HPP_ */
