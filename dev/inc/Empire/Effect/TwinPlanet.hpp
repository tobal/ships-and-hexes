
#ifndef TWINPLANET_HPP_
#define TWINPLANET_HPP_

#include "Empire/Effect/MapEffect.hpp"
#include <string>

namespace Empire
{
namespace Effect
{

class TwinPlanet : public MapEffect
{
public:
	TwinPlanet(std::string playerName);
	~TwinPlanet();
};

} /* namespace Effect */
} /* namespace Empire */

#endif /* TWINPLANET_HPP_ */
