
#ifndef GAMEMAPGENERATOR_HPP_
#define GAMEMAPGENERATOR_HPP_

#include <vector>
#include <math.h>
#include <time.h>
#include "GameMap/GameMap.hpp"
#include "GameMap/GameMapImpl.hpp"
#include "GameMap/Hex.hpp"
#include "MapElement/MapElementFactory.hpp"
#include "Empire/CommonTypes.hpp"
#include "Empire/Effect/Effect.hpp"

namespace GameMap
{

struct Section
{
	Section() : coords(std::vector<Coord>()), orbitalCount(0) {}
	std::vector<Coord> coords;
	int orbitalCount;
};

typedef std::vector<Section> Sections;

class GameMapGenerator
{
private:
	MapElement::MapElementFactory* neutralFactory;
	Sections sliceMapIntoSections(Coord* dimensions);
	Sections calculateOrbitalCount(Sections sections, Coord* dimensions, const int density);
	GameMap* generateOrbitals(GameMap* map, Sections sections);
	bool noPlanetInVicinity(GameMap* map, Coord center) const;
	PlanetType pickRandomType();
	PlanetSize pickRandomSize();
	Empire::Effect::Effect* pickRandomEffect();

public:
	GameMapGenerator();
	~GameMapGenerator();
	GameMap* generateMap(const Coord& dimensions) const;
	GameMap* generateMap(const Coord& dimensions, const int density);
};

}


#endif /* GAMEMAPGENERATOR_HPP_ */
