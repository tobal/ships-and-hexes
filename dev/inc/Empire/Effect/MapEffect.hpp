
#ifndef MAPEFFECT_HPP_
#define MAPEFFECT_HPP_

#include "Empire/Effect/Effect.hpp"
#include "GameMap/GameMap.hpp"
#include "MapElement/Planet.hpp"

namespace Empire
{
namespace Effect
{

class MapEffect : public Effect::Effect
{
public:
	MapEffect() {}
	virtual ~MapEffect() {}
	virtual void applyEffect(GameMap::GameMap* map, Coord homeworld, MapElement::Planet* planet) {}
};

typedef std::vector<MapEffect*> MapEffects;

} /* namespace Effect */
} /* namespace Empire */

#endif /* MAPEFFECT_HPP_ */
