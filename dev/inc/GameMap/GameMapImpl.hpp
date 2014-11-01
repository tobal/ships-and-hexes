
#ifndef GAMEMAPIMPL_HPP_
#define GAMEMAPIMPL_HPP_

#include <vector>
#include <set>
#include "GameMap/GameMap.hpp"
#include "GameMap/Hex.hpp"
#include "Empire/CommonTypes.hpp"

namespace GameMap
{
typedef std::vector< HexVector* > HexMap;

class GameMapImpl;

// TODO: extract this to separate file
// TODO: root out circular dependency
class CircularMapIterator
{
private:
	GameMapImpl& parent;
	Coord origo;
	int radius;
	std::set<Coord> vicinity;
	std::set<Coord>::iterator hexIt;

	std::set<Coord> expandVicinity(const std::set<Coord> vicinity);

public:
	CircularMapIterator(GameMapImpl& parent, Coord origo, int radius);
	~CircularMapIterator();
	bool hasNext();
	Hex* next();
	Coord nextCoord();
};

class GameMapImpl : public GameMap
{
private:
	HexMap* hexMap;
	Coord dimensions;

	void addCoordToVector(Coords& coords, int x, int y);

public:
	GameMapImpl(const int x, const int y);
	~GameMapImpl();

	Coord getDimensions();
	Hex* getHexOnCoord(Coord coord);
	Coords getCoordNeighbours(Coord coord);
	CircularMapIterator getCircularIterator(Coord origo, int radius);
	bool isObjectInVicinity(MapElementType type, Coord coord, int radius);
	Coords getPlanets();
	int countPlanetsOfPlayer(std::string playerName);
	Coords getPlanetsOfPlayer(std::string playerName);
	Coords getObjects(MapElementType type);
	Coords getFleets();
	Coords getTrail(Coord source, Coord destination);
	Coord getNextOnTrail(Coord source, Coord destination);
};

}

#endif /* GAMEMAPIMPL_HPP_ */
