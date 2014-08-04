
#include "GameMap/GameMapGenerator.hpp"

using namespace GameMap;
using namespace std;

GameMapGenerator::GameMapGenerator()
{

}

GameMapGenerator::~GameMapGenerator()
{

}

GameMap::GameMap* GameMapGenerator::generateMap(const Coord& dimensions) const
{
	return new GameMapImpl(dimensions.x, dimensions.y);
}
