
#include "Empire/Effect/PopulationBonus.hpp"

using namespace Empire::Effect;

PopulationBonus::PopulationBonus()
{

}

PopulationBonus::~PopulationBonus()
{

}

void PopulationBonus::setEffectByShipControl(const int control)
{
	effectMultiplier = computeMultiplier(double(control));
}
