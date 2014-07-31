
#include "GameMap/GameMapImpl.hpp"

using namespace GameMap;
using namespace std;

GameMapImpl::CircularMapIterator::CircularMapIterator(GameMapImpl& parent, Coord origo, int radius)
 : parent(parent), origo(origo), radius(radius)
{
	vicinity = set<Coord>();
	vicinity.insert(origo);
	for (int i = 0; i < radius; ++i)
	{
		vicinity = expandVicinity(vicinity);
	}
	hexIt = vicinity.begin();
}

GameMapImpl::CircularMapIterator::~CircularMapIterator()
{
}

set<Coord> GameMapImpl::CircularMapIterator::expandVicinity(const set<Coord> vicinity)
{
	set<Coord> expanded = set<Coord>();
	for(set<Coord>::iterator it = vicinity.begin(); it != vicinity.end(); it++)
	{
		Coords neighbours = parent.getCoordNeighbours(*it);
		for(Coords::iterator cit = neighbours.begin(); cit != neighbours.end(); cit++)
		{
			if(*cit != origo)
			{
				expanded.insert(*cit);
			}
		}
	}
	return expanded;
}

bool GameMapImpl::CircularMapIterator::hasNext()
{
	return hexIt != vicinity.end();
}

Hex* GameMapImpl::CircularMapIterator::next()
{
	return parent.getHexOnCoord(nextCoord());
}

Coord GameMapImpl::CircularMapIterator::nextCoord()
{
	return *hexIt++;
}

GameMapImpl::CircularMapIterator GameMapImpl::getCircularIterator(Coord origo, int radius)
{
	return CircularMapIterator(*this, origo, radius);
}

GameMapImpl::GameMapImpl(const int x, const int y) : dimensions(new Coord(x, y))
{
	hexMap = new HexMap();
	for (int i = 0; i < x; ++i)
	{
		hexMap->push_back(new HexVector());
		for (int j = 0; j < y; ++j)
		{
			hexMap->at(i)->push_back(new Hex());
		}
	}
}

GameMapImpl::~GameMapImpl()
{
	for (int i = 0; i < dimensions->x; ++i)
	{
		for (int j = 0; j < dimensions->y; ++j)
		{
			delete hexMap->at(i)->at(j);
		}
		delete hexMap->at(i);
	}
	delete hexMap;
	delete dimensions;
}

Coord* GameMapImpl::getDimensions()
{
	return dimensions;
}

Hex* GameMapImpl::getHexOnCoord(Coord coord)
{
	return hexMap->at(coord.x)->at(coord.y);
}

void GameMapImpl::addCoordToVector(Coords& coords, int x, int y)
{
	if(x >= 0 && x <= dimensions->x - 1 &&
	   y >= 0 && y <= dimensions->y - 1)
	{
		coords.push_back(Coord(x, y));
	}
}

Coords GameMapImpl::getCoordNeighbours(Coord coord)
{
	Coords coords = Coords();
	int x = coord.x;
	int y = coord.y;
	if(coord.y % 2 == 0)
	{
		addCoordToVector(coords, x - 1, y - 1);
		addCoordToVector(coords, x - 1, y);
		addCoordToVector(coords, x - 1, y + 1);
		addCoordToVector(coords, x, y + 1);
		addCoordToVector(coords, x + 1, y);
		addCoordToVector(coords, x, y - 1);
	}
	else
	{
		addCoordToVector(coords, x, y - 1);
		addCoordToVector(coords, x - 1, y);
		addCoordToVector(coords, x, y + 1);
		addCoordToVector(coords, x + 1, y + 1);
		addCoordToVector(coords, x + 1, y);
		addCoordToVector(coords, x + 1, y - 1);
	}
	return coords;
}

bool GameMapImpl::isObjectInVicinity(MapElementType type, Coord coord, int radius)
{
	GameMapImpl::CircularMapIterator vicinity = this->getCircularIterator(coord, radius);
	for(Hex* hex; vicinity.hasNext(); hex = vicinity.next())
	{
		if(hex->getSpaceObjectType() == type)
		{
			return true;
		}
	}
	return false;
}

