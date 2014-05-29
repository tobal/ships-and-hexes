
#ifndef RESEARCHBONUS_HPP_
#define RESEARCHBONUS_HPP_

#include "Empire/Effect/EmpireEffect.hpp"

namespace Empire
{
namespace Effect
{

class ResearchBonus : public EmpireEffect
{
public:
	ResearchBonus();
	~ResearchBonus();
	void setEffectByShipControl(const int control);
};

} /* namespace Effect */
} /* namespace Empire */

#endif /* RESEARCHBONUS_HPP_ */
