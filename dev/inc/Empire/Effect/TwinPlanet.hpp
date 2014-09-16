
#ifndef TWINPLANET_HPP_
#define TWINPLANET_HPP_

#include "Empire/Effect/MapEffect.hpp"
#include "GameMap/GameMap.hpp"
#include "GameMap/GameMapImpl.hpp"
#include "MapElement/Planet.hpp"
#include <string>

namespace Empire
{
namespace Effect
{

class TwinPlanet : public MapEffect
{
public:
	TwinPlanet();
	~TwinPlanet();
	void applyEffect(GameMap::GameMap* map, Coord homeworld, MapElement::Planet* planet);
};

} /* namespace Effect */
} /* namespace Empire */

#endif /* TWINPLANET_HPP_ */
