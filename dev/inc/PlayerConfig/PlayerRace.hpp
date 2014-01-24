
#ifndef PLAYERRACE_HPP_
#define PLAYERRACE_HPP_

#include <vector>
#include <map>

namespace PlayerConfig
{

// TODO: remove these two, replace with actual data classes
typedef int Effect;
typedef int BuildingType;
// TODO: after replaced with classes, add more tests to test them

typedef std::vector<Effect> Effects;

enum RaceType
{
	HUMAN,
	AMAZON,
	INSECTOID,
	TENTACLE,
	SILICONITIS,
	MECHANIZED
};

enum CredoType
{
	EXPANSIONIST,
	WARMONGER,
	SCIENTIFIC,
	UNIFIED,
	JACKOFALL,
	ALTERNATE
};

struct Credo
{
	Credo(CredoType type, int traitPoints, Effects effects, BuildingType specialBuilding)
		: type(type), traitPoints(traitPoints), effects(effects), specialBuilding(specialBuilding) {}
	CredoType type;
	int traitPoints;
	Effects effects;
	BuildingType specialBuilding;
};

// TODO: put this to a better place
enum PlanetType
{
	WATER,
	DESERT,
	LAVA
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
