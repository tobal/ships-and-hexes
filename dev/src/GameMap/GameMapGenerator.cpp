
#include "GameMap/GameMapGenerator.hpp"

using namespace GameMap;
using namespace MapElement;
using namespace std;

GameMapGenerator::GameMapGenerator()
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
	GameMap* map = this->generateMap(dimensions);
	Sections sections = sliceMapIntoSections(map->getDimensions());
	sections = calculateOrbitalCount(sections, map->getDimensions(), density);
	map = generateOrbitals(map, sections);
	return map;
}

Sections GameMapGenerator::sliceMapIntoSections(Coord* dimensions)
{
	Coord sectionDims(int(dimensions->x / 3), int(dimensions->y) / 3);
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

Sections GameMapGenerator::calculateOrbitalCount(Sections sections, Coord* dimensions, const int density)
{
	int realDensity = int(ceil(density / 3.5));
	int hexesOnMap = dimensions->x * dimensions->y;
	int planetsOnMap = int( (realDensity*100) / hexesOnMap );
	int planetsInOneSection = floor(planetsOnMap / sections.size());
	for(Sections::iterator it = sections.begin(); it != sections.end(); ++it)
	{
		(*it).orbitalCount = planetsInOneSection;
	}
	sections.at(0).orbitalCount += planetsOnMap % sections.size();
	return sections;
}

GameMap::GameMap* GameMapGenerator::generateOrbitals(GameMap* map, Sections sections)
{
	int carry = 0;
	for(Sections::iterator it = sections.begin(); it != sections.end(); ++it)
	{
		for (int i = 0; i < 5; ++i)
		{
			srand(time(NULL));
			int pick = rand() % (*it).coords.size();
			Coord pickedHex = (*it).coords.at(pick);
			if(noPlanetInVicinity(map, pickedHex))
			{
				(*it).orbitalCount -= 1;
				Planet* planet = neutralFactory->createPlanet(
						pickRandomType(), pickRandomSize(), pickRandomEffect());
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

bool GameMapGenerator::noPlanetInVicinity(GameMap* map, Coord center) const
{
	return ! map->isObjectInVicinity(PLANET, center, 1);
}

PlanetType GameMapGenerator::pickRandomType()
{
	// FIXME: don't depend on fix size of enum
	srand(time(NULL));
	return PlanetType(rand() % 3);
}

PlanetSize GameMapGenerator::pickRandomSize()
{
	// FIXME: don't depend on fix size of enum
	srand(time(NULL));
	return PlanetSize(rand() % 3);
}

Empire::Effect::Effect* GameMapGenerator::pickRandomEffect()
{
	// TODO: pick real planet effect
	return new Empire::Effect::Effect();
}
