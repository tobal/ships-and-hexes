
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
	int planetsOnMap;
	Sections sliceMapIntoSections(const Coord& dimensions);
	Sections calculateOrbitalCount(Sections sections);
	void calculatePlanetsOnMap(const Coord& dimensions, const int density);
	void generateOrbitals(GameMap* map, Sections sections);
	void generatePlanets(GameMap* map, Sections sections);
	void generateAnomalies(GameMap* map);
	bool noPlanetInVicinity(GameMap* map, Coord center) const;
	bool noAnomalyInVicinity(GameMap* map, Coord center) const;
	PlanetType pickRandomPlanetType();
	PlanetSize pickRandomPlanetSize();
	Empire::Effect::Effect* pickRandomPlanetEffect();
	AnomalyType pickRandomAnomalyType();
	AnomalySize pickRandomAnomalySize();

public:
	GameMapGenerator();
	~GameMapGenerator();
	GameMap* generateMap(const Coord& dimensions) const;
	GameMap* generateMap(const Coord& dimensions, const int density);
	void putRandomAnomaly(GameMap* map);
};

}


#endif /* GAMEMAPGENERATOR_HPP_ */
