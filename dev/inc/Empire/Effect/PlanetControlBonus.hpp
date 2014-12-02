
#ifndef PLANETCONTROLBONUS_HPP_
#define PLANETCONTROLBONUS_HPP_

#include "Empire/Effect/EmpireEffect.hpp"

namespace Empire
{
namespace Effect
{

class PlanetControlBonus : public Effect
{
public:
	int planetControl;

public:
	PlanetControlBonus();
	~PlanetControlBonus();
	void setEffectByEmpireResearchLevel(const int level);
	int getControlBonus() const;
};

} /* namespace Effect */
} /* namespace Empire */

#endif /* PLANETCONTROLBONUS_HPP_ */
