
#ifndef COMMONTYPES_HPP_
#define COMMONTYPES_HPP_

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

enum PlanetType
{
	WATER,
	DESERT,
	LAVA
};

enum PlanetSize
{
	SMALL,
	MEDIUM,
	LARGE
};

enum AnomalyType
{
	ASTEROIDFIELD,
	GASCLOUD,
	ALIENWRECK
};

enum AnomalySize
{
	LITTLE,
	BIG
};

enum MapElementType
{
	SHIP,
	PLANET,
	ANOMALY,
	SPACESTATION
};

struct Coord
{
	Coord(const int x, const int y) : x(x), y(y) {}
	int x;
	int y;
};

#endif /* COMMONTYPES_HPP_ */
