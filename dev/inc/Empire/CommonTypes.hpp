
#ifndef COMMONTYPES_HPP_
#define COMMONTYPES_HPP_

#include <vector>

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
	FLEET,
	PLANET,
	ANOMALY,
	SPACESTATION,
	NOTHING
};

struct Coord
{
	Coord(const int x, const int y) : x(x), y(y) {}
	int x;
	int y;

//	inline bool operator=(const Coord& rhs) const
//	{
//		return this->x = rhs.x && this->y = rhs.y;
//	}

	inline bool operator==(const Coord& rhs) const
	{
		return this->x == rhs.x && this->y == rhs.y;
	}

	inline bool operator!=(const Coord& rhs) const
	{
		return this->x != rhs.x || this->y != rhs.y;
	}
};

inline bool operator<(const Coord& lhs, const Coord& rhs)
{
	if (lhs.x < rhs.x) return true;
	else if ( (lhs.x == rhs.x) && (lhs.y < rhs.y) ) return true;
	else return false;
}

typedef std::vector<Coord> Coords;

#endif /* COMMONTYPES_HPP_ */
