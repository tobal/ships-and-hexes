
#ifndef PLAYERCONFIGIMPL_HPP_
#define PLAYERCONFIGIMPL_HPP_

#include "PlayerConfig/PlayerConfig.hpp"
#include "PlayerConfig/PlayerRace.hpp"
#include "PlayerConfig/Randomizer.hpp"
#include "PlayerConfig/Trait.hpp"
#include "Exceptions/TraitPointsNotSpentException.hpp"

namespace PlayerConfig
{

class PlayerConfigImpl : public PlayerConfig
{
private:
	PlayerRace* race;
	Randomizer* randomizer;
	Traits* allTraits;
	std::vector<int>* pickedIndexes;

	void constructTraits();

public:
	PlayerConfigImpl();
	~PlayerConfigImpl();
	RaceType getRaceType() const;
	Credo getCredo() const;
	void setRace(const RaceType raceType);
	PlanetType getHomeworld() const;
	void setHomeworld(const PlanetType planetType);
	CredoType getCredoType() const;
	void setCredo(const CredoType credoType);
	Traits getAllTraits() const;
	void pickTraits(std::vector<int> picked) throw(TraitPointsNotSpentException);
	Traits getPickedTraits() const;
	void pickRandomTraits();
	Empire::Effect::Effects getAllEffects() const;
};

}

#endif /* PLAYERCONFIGIMPL_HPP_ */
