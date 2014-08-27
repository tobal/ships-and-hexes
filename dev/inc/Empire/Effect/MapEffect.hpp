
#ifndef MAPEFFECT_HPP_
#define MAPEFFECT_HPP_

#include "Empire/Effect/Effect.hpp"

namespace Empire
{
namespace Effect
{

class MapEffect : public Effect::Effect
{
public:
	MapEffect() {}
	virtual ~MapEffect() {}
};

typedef std::vector<MapEffect> MapEffects;

} /* namespace Effect */
} /* namespace Empire */

#endif /* MAPEFFECT_HPP_ */
