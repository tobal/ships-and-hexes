
#ifndef EFFECT_HPP_
#define EFFECT_HPP_

#include <vector>

namespace Empire
{
namespace Effect
{

class Effect
{
public:
	Effect() {}
	virtual ~Effect() {}
	virtual void applyEffect() {}
};

typedef std::vector<Effect> Effects;

} /* namespace Effect */
} /* namespace Empire */

#endif /* EFFECT_HPP_ */
