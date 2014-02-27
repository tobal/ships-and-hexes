
#ifndef PLAYERCONFIG_HPP_
#define PLAYERCONFIG_HPP_

#include "Empire/CommonTypes.hpp"
#include "PlayerConfig/Trait.hpp"
#include "PlayerConfig/PlayerRace.hpp"

namespace PlayerConfig
{

class PlayerConfig
{
public:
	PlayerConfig() {}
	virtual ~PlayerConfig() {}
	virtual RaceType getRaceType() const {}
	virtual Credo getCredo() const {}
	virtual void setRace(const RaceType raceType) {}
	virtual PlanetType getHomeworld() const {}
	virtual void setHomeworld(const PlanetType planetType) {}
	virtual CredoType getCredoType() const {}
	virtual void setCredo(const CredoType credoType) {}
	virtual Traits getAllTraits() const {}
	virtual void pickTraits(std::vector<int> picked) {}
	virtual Traits getPickedTraits() const {}
	virtual void pickRandomTraits() {}
	virtual Effects getAllEffects() const {}
};

}

#endif /* PLAYERCONFIG_HPP_ */
