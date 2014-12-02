
#include "Empire/Effect/PlanetControlBonus.hpp"

using namespace Empire::Effect;

PlanetControlBonus::PlanetControlBonus() : Effect(), planetControl(0)
{

}

PlanetControlBonus::~PlanetControlBonus()
{

}

void PlanetControlBonus::setEffectByEmpireResearchLevel(const int level)
{
	// TODO figure out the correct formula
	planetControl = level * level;
}

int PlanetControlBonus::getControlBonus() const
{
	return planetControl;
}
