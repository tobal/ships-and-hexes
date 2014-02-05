
#ifndef PLAYERRACE_HPP_
#define PLAYERRACE_HPP_

#include <vector>
#include <map>
#include "Empire/CommonTypes.hpp"

namespace PlayerConfig
{

// TODO: remove, replace with mocks
typedef int BuildingType;

struct Credo
{
	Credo(CredoType type, int traitPoints, Effects effects, BuildingType specialBuilding)
		: type(type), traitPoints(traitPoints), effects(effects), specialBuilding(specialBuilding) {}
	CredoType type;
	int traitPoints;
	Effects effects;
	BuildingType specialBuilding;
};

struct Race
{
	Race() : type(HUMAN), homeworld(WATER), credo(JACKOFALL) {}
	Race(RaceType type, PlanetType homeworld, CredoType credo)
		: type(type), homeworld(homeworld), credo(credo) {}
	RaceType type;
	PlanetType homeworld;
	CredoType credo;
};

typedef std::pair<CredoType, Credo> CredoPair;
typedef std::map<CredoType, Credo> CredoPrototypes;
typedef std::pair<RaceType, Race> RacePair;
typedef std::map<RaceType, Race> RacePrototypes;

class PlayerRace
{
private:
	Race race;
	CredoPrototypes* credoPrototypes;
	RacePrototypes* racePrototypes;

	void createCredoPrototypes();
	void addCredoPrototype(CredoType type, int traitPoints, Effects effects, BuildingType specialBuilding);
	void createRacePrototypes();
	void addRacePrototype(RaceType type, PlanetType homeworld, CredoType credo);

public:
	PlayerRace(RaceType raceType);
	~PlayerRace();
	RaceType getRaceType() const;
	PlanetType getHomeworldType() const;
	CredoType getCredoType() const;
	Credo getCredo() const;
	void setRace(const RaceType raceType);
	void setHomeworld(const PlanetType homeworld);
	void setCredo(const CredoType credo);
};

}

#endif /* PLAYERRACE_HPP_ */
