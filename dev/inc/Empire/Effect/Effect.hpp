
#ifndef EFFECT_HPP_
#define EFFECT_HPP_

#include <vector>

namespace Empire
{
namespace Effect
{

class Effect
{
// TODO: make constructors and destructors private in all abstract classes
public:
	Effect() {}
	virtual ~Effect() {}
	virtual void applyEffect() {}
};

// TODO: implement concrete subclasses

typedef std::vector<Effect*> Effects;

} /* namespace Effect */
} /* namespace Empire */

#endif /* EFFECT_HPP_ */
