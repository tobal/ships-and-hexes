
#ifndef PLAYERCONFIG_HPP_
#define PLAYERCONFIG_HPP_

#include "Empire/CommonTypes.hpp"

namespace PlayerConfig
{

class PlayerConfig
{
public:
	PlayerConfig() {}
	virtual ~PlayerConfig() {}
	virtual RaceType getRace() const {}
	virtual void setRace(const RaceType raceType) {}
	virtual PlanetType getHomeworld() const {}
	virtual void setHomeworld(const PlanetType planetType) {}
	virtual CredoType getCredo() const {}
	virtual void setCredo(const CredoType credoType) {}
};

}

#endif /* PLAYERCONFIG_HPP_ */
