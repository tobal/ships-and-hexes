
#ifndef TWINPLANET_HPP_
#define TWINPLANET_HPP_

#include "Empire/Effect/MapEffect.hpp"
#include "GameMap/GameMap.hpp"
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
	void applyEffect(GameMap::GameMap* map, Coord homeworld);
};

} /* namespace Effect */
} /* namespace Empire */

#endif /* TWINPLANET_HPP_ */
