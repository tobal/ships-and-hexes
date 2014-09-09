
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
#include "Empire/Effect/MapEffect.hpp"
#include "GameConfig/Player.hpp"

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
	void placePlayersOnMap(GameMap* map, GameConfig::Players players);
	Coord getRandomPlanetCoord(Coords planets);
	void swapPlanetToHomeworld(GameMap* map, GameConfig::Player player, Coord planetCoord);
	PlanetType pickRandomPlanetType();
	PlanetSize pickRandomPlanetSize();
	Empire::Effect::Effect* pickRandomPlanetEffect();
	AnomalyType pickRandomAnomalyType();
	AnomalySize pickRandomAnomalySize();
	std::set<Coord> pickRandomPlanets(GameConfig::Players& players, Coords planets);

public:
	GameMapGenerator();
	~GameMapGenerator();
	GameMap* generateMap(const Coord& dimensions) const;
	GameMap* generateMap(const Coord& dimensions, const int density);
	GameMap* generateMap(const Coord& dimensions, const int density, GameConfig::Players players);
	GameMap* generateMap(const Coord& dimensions, const int density, GameConfig::Players players,
						 Empire::Effect::MapEffects mapEffects);
	void putRandomAnomaly(GameMap* map);
};

}


#endif /* GAMEMAPGENERATOR_HPP_ */
