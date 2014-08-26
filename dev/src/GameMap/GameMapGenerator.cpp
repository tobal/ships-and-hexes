
#include "GameMap/GameMapGenerator.hpp"

using namespace GameMap;
using namespace GameConfig;
using namespace MapElement;
using namespace std;

GameMapGenerator::GameMapGenerator() : planetsOnMap(0)
{
	neutralFactory = new MapElementFactory("nobody");
}

GameMapGenerator::~GameMapGenerator()
{
	delete neutralFactory;
}

GameMap::GameMap* GameMapGenerator::generateMap(const Coord& dimensions) const
{
	return new GameMapImpl(dimensions.x, dimensions.y);
}

GameMap::GameMap* GameMapGenerator::generateMap(const Coord& dimensions, const int density)
{
	calculatePlanetsOnMap(dimensions, density);
	GameMap* map = this->generateMap(dimensions);
	Sections sections = sliceMapIntoSections(dimensions);
	sections = calculateOrbitalCount(sections);
	generateOrbitals(map, sections);
	return map;
}

GameMap::GameMap* GameMapGenerator::generateMap(const Coord& dimensions, const int density, Players players)
{
	GameMap* map = this->generateMap(dimensions, density);
	Sections sections = sliceMapIntoSections(dimensions);
	placePlayersOnMap(map, players);
	return map;
}

Sections GameMapGenerator::sliceMapIntoSections(const Coord& dimensions)
{
	Coord sectionDims(int(dimensions.x / 3), int(dimensions.y / 3));
	Sections sections = Sections();
	for (int x = 0; x < sectionDims.x; ++x)
	{
		for (int y = 0; y < sectionDims.y; ++y)
		{
			Section section = Section();
			section.coords.push_back(Coord(x * 3, y * 3));
			section.coords.push_back(Coord(x * 3 + 1, y * 3));
			section.coords.push_back(Coord(x * 3 + 2, y * 3));
			section.coords.push_back(Coord(x * 3, y * 3 + 1));
			section.coords.push_back(Coord(x * 3 + 1, y * 3 + 1));
			section.coords.push_back(Coord(x * 3 + 2, y * 3 + 1));
			section.coords.push_back(Coord(x * 3, y * 3 + 2));
			section.coords.push_back(Coord(x * 3 + 1, y * 3 + 2));
			section.coords.push_back(Coord(x * 3 + 2, y * 3 + 2));

			sections.push_back(section);
		}
	}
	return sections;
}

Sections GameMapGenerator::calculateOrbitalCount(Sections sections)
{
	size_t s = sections.size();
	int planetsInOneSection = floor(planetsOnMap / sections.size());
	for(Sections::iterator it = sections.begin(); it != sections.end(); ++it)
	{
		(*it).orbitalCount = planetsInOneSection;
	}
	int o = planetsOnMap % sections.size();
	sections.at(0).orbitalCount += planetsOnMap % sections.size();
	return sections;
}

void GameMapGenerator::calculatePlanetsOnMap(const Coord& dimensions, const int density)
{
	int realDensity = int(ceil(density / 3.5));
	int hexesOnMap = dimensions.x * dimensions.y;
	planetsOnMap = int( (realDensity/100.0) * hexesOnMap );
}

void GameMapGenerator::generateOrbitals(GameMap* map, Sections sections)
{
	srand(time(NULL));
	generatePlanets(map, sections);
	generateAnomalies(map);
}

void GameMapGenerator::generatePlanets(GameMap* map, Sections sections)
{
	int carry = 0;
	for(Sections::iterator it = sections.begin(); it != sections.end(); ++it)
	{
		(*it).orbitalCount += carry;
		for (int i = 0; i < 5; ++i)
		{
			int pick = rand() % (*it).coords.size();
			Coord pickedHex = (*it).coords.at(pick);
			if(noPlanetInVicinity(map, pickedHex))
			{
				(*it).orbitalCount -= 1;
				Planet* planet = neutralFactory->createPlanet(
						pickRandomPlanetType(), pickRandomPlanetSize(), pickRandomPlanetEffect());
				map->getHexOnCoord(pickedHex)->addSpaceObject(planet);
			}
			if((*it).orbitalCount == 0)
			{
				break;
			}
		}
		carry = (*it).orbitalCount;
	}
}

void GameMapGenerator::generateAnomalies(GameMap* map)
{
	int anomaliesOnMap = floor(planetsOnMap / 2.0);
	while(anomaliesOnMap != 0)
	{
		putRandomAnomaly(map);
		anomaliesOnMap--;
	}
}

void GameMapGenerator::putRandomAnomaly(GameMap* map)
{
	Coord dimensions = map->getDimensions();
	while(true)
	{
		int pickedX = rand() % dimensions.x;
		int pickedY = rand() % dimensions.y;
		Coord pickedHex = Coord(pickedX, pickedY);
		if(noAnomalyInVicinity(map, pickedHex))
		{
			Anomaly* anomaly = neutralFactory->createAnomaly(
					pickRandomAnomalyType(), pickRandomAnomalySize());
			map->getHexOnCoord(pickedHex)->addSpaceObject(anomaly);
			break;
		}
	}
}

bool GameMapGenerator::noPlanetInVicinity(GameMap* map, Coord center) const
{
	return ! map->isObjectInVicinity(PLANET, center, 1);
}

bool GameMapGenerator::noAnomalyInVicinity(GameMap* map, Coord center) const
{
	return ! map->isObjectInVicinity(ANOMALY, center, 1);
}

void GameMapGenerator::placePlayersOnMap(GameMap* map, Players players)
{
	for (Players::iterator player = players.begin(); player != players.end(); ++player)
	{
		Coords planets = map->getPlanets();
		Coord randomPlanet = getRandomPlanetCoord(planets);
		swapPlanetToHomeworld(map, *player, randomPlanet);
	}
}

Coord GameMapGenerator::getRandomPlanetCoord(Coords planets)
{
	return planets.at(rand() % planets.size());
}

void GameMapGenerator::swapPlanetToHomeworld(GameMap* map, Player player, Coord planetCoord)
{
	map->getHexOnCoord(planetCoord)->removeSpaceObject();
	MapElementFactory* playerFactory = new MapElementFactory(player.getName());
	Planet* homeworld = playerFactory->createPlanet(player.getPlayerConfig()->getHomeworld(),
												  LARGE, pickRandomPlanetEffect());
	map->getHexOnCoord(planetCoord)->addSpaceObject(homeworld);
	delete playerFactory;
}

PlanetType GameMapGenerator::pickRandomPlanetType()
{
	// FIXME: don't depend on fix size of enum
	return PlanetType(rand() % 3);
}

PlanetSize GameMapGenerator::pickRandomPlanetSize()
{
	// FIXME: don't depend on fix size of enum
	return PlanetSize(rand() % 3);
}

Empire::Effect::Effect* GameMapGenerator::pickRandomPlanetEffect()
{
	// TODO: pick real planet effect
	return new Empire::Effect::Effect();
}

AnomalyType GameMapGenerator::pickRandomAnomalyType()
{
	// FIXME: don't depend on fix size of enum
	return AnomalyType(rand() % 3);
}

AnomalySize GameMapGenerator::pickRandomAnomalySize()
{
	// FIXME: don't depend on fix size of enum
	return AnomalySize(rand() % 2);
}
