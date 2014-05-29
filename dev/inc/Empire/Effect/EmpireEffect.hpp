
#ifndef EMPIREEFFECT_HPP_
#define EMPIREEFFECT_HPP_

#include "Empire/Effect/Effect.hpp"

namespace Empire
{
namespace Effect
{

class EmpireEffect : public Effect::Effect
{
protected:
	double effectMultiplier;
	double computeMultiplier(const double control) const { return (control / 100.0) + 1.0; }

public:
	EmpireEffect() : effectMultiplier(0.0) {}
	virtual ~EmpireEffect() {}
	double getEffectMultiplier() const { return effectMultiplier; }
	virtual void setEffectByShipControl(const int control) {}
};

} /* namespace Effect */
} /* namespace Empire */

#endif /* EMPIREEFFECT_HPP_ */
