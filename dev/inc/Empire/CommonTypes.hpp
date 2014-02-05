
#ifndef COMMONTYPES_HPP_
#define COMMONTYPES_HPP_

#include <vector>

// TODO: implement Effect class
typedef int Effect;
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

// TODO: put this to Empire package
enum PlanetType
{
	WATER,
	DESERT,
	LAVA
};

#endif /* COMMONTYPES_HPP_ */
