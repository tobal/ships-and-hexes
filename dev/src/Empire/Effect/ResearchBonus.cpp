
#include "Empire/Effect/ResearchBonus.hpp"

using namespace Empire::Effect;

ResearchBonus::ResearchBonus() : EmpireEffect()
{

}

ResearchBonus::~ResearchBonus()
{

}

void ResearchBonus::setEffectByShipControl(const int control)
{
	effectMultiplier = computeMultiplier(double(control));
}
