
#ifndef PLAYERCONFIGIMPL_HPP_
#define PLAYERCONFIGIMPL_HPP_

#include "PlayerConfig/PlayerConfig.hpp"
#include "PlayerConfig/PlayerRace.hpp"
#include "PlayerConfig/Randomizer.hpp"
#include "PlayerConfig/Trait.hpp"

namespace PlayerConfig
{

class PlayerConfigImpl : public PlayerConfig
{
private:
	PlayerRace* race;
	Randomizer* randomizer;
	// TODO: make traits static
	Traits* traits;

	void constructTraits();

public:
	PlayerConfigImpl();
	~PlayerConfigImpl();
	RaceType getRace() const;
	void setRace(const RaceType raceType);
	PlanetType getHomeworld() const;
	void setHomeworld(const PlanetType planetType);
	CredoType getCredo() const;
	void setCredo(const CredoType credoType);
};

}

#endif /* PLAYERCONFIGIMPL_HPP_ */
