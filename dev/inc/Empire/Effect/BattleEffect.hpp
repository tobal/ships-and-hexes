
#ifndef BATTLEEFFECT_HPP_
#define BATTLEEFFECT_HPP_

#include "Empire/Effect/Effect.hpp"

namespace Empire
{
namespace Effect
{

class BattleEffect : public Effect::Effect
{
public:
	BattleEffect() {}
	virtual ~BattleEffect() {}
	// TODO: make this pure virtual
	virtual bool condition() {}
};

} /* namespace Effect */
} /* namespace Empire */

#endif /* BATTLEEFFECT_HPP_ */
