
#ifndef PLAYERRACE_HPP_
#define PLAYERRACE_HPP_

#include <vector>

namespace PlayerConfig
{

// TODO: remove these two
typedef int Effect;
typedef int BuildingType;

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
	RaceType type;
	PlanetType defaultHomeworld;
	CredoType defaultCredo;
};

class PlayerRace
{
private:
	Race race;
	PlanetType homeworldType;
	Credo credo;

public:
	PlayerRace();
	~PlayerRace();
};

}

#endif /* PLAYERRACE_HPP_ */
