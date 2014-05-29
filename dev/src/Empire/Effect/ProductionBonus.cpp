
#include "Empire/Effect/ProductionBonus.hpp"

using namespace Empire::Effect;

ProductionBonus::ProductionBonus() : EmpireEffect()
{

}

ProductionBonus::~ProductionBonus()
{

}

void ProductionBonus::setEffectByShipControl(const int control)
{
	effectMultiplier = computeMultiplier(double(control));
}
