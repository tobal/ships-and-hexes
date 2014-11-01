
#include "GameMap/GameMapImpl.hpp"

using namespace GameMap;
using namespace std;

CircularMapIterator::CircularMapIterator(GameMapImpl& parent, Coord origo, int radius)
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

CircularMapIterator::~CircularMapIterator()
{
}

set<Coord> CircularMapIterator::expandVicinity(const set<Coord> vicinity)
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

bool CircularMapIterator::hasNext()
{
	return hexIt != vicinity.end();
}

Hex* CircularMapIterator::next()
{
	Coord c = nextCoord();
	Hex* h = parent.getHexOnCoord(c);
	return h;
}

Coord CircularMapIterator::nextCoord()
{
	Coord c = *(hexIt++);
	return c;
}

CircularMapIterator GameMapImpl::getCircularIterator(Coord origo, int radius)
{
	return CircularMapIterator(*this, origo, radius);
}

GameMapImpl::GameMapImpl(const int x, const int y) : dimensions(Coord(x, y))
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
	for (int i = 0; i < dimensions.x; ++i)
	{
		for (int j = 0; j < dimensions.y; ++j)
		{
			delete hexMap->at(i)->at(j);
		}
		delete hexMap->at(i);
	}
	delete hexMap;
}

Coord GameMapImpl::getDimensions()
{
	return dimensions;
}

Hex* GameMapImpl::getHexOnCoord(Coord coord)
{
	return hexMap->at(coord.x)->at(coord.y);
}

void GameMapImpl::addCoordToVector(Coords& coords, int x, int y)
{
	if(x >= 0 && x <= dimensions.x - 1 &&
	   y >= 0 && y <= dimensions.y - 1)
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
	CircularMapIterator vicinity = this->getCircularIterator(coord, radius);
	if(getHexOnCoord(coord)->getSpaceObjectType() != NOTHING)
	{
		return true;
	}
	while(vicinity.hasNext())
	{
		Hex* hex = vicinity.next();
		if(hex->getSpaceObjectType() == type)
		{
			return true;
		}
	}
	return false;
}

// TODO: substitute this function from call sites
Coords GameMapImpl::getPlanets()
{
	return getObjects(PLANET);
}

int GameMapImpl::countPlanetsOfPlayer(std::string playerName)
{
	return int(this->getPlanetsOfPlayer(playerName).size());
}

Coords GameMapImpl::getPlanetsOfPlayer(std::string playerName)
{
	Coords coords = Coords();
	Coords planets = getPlanets();
	for (Coords::iterator planet = planets.begin(); planet != planets.end(); ++planet)
	{
		Hex* hex = this->getHexOnCoord(*planet);
		if(hex->getSpaceObject()->getPlayerName() == playerName)
		{
			coords.push_back(*planet);
		}
	}
	return coords;
}

Coords GameMapImpl::getObjects(MapElementType type)
{
	Coords objects = Coords();
	for (int i = 0; i < dimensions.x; ++i)
	{
		for (int j = 0; j < dimensions.y; ++j)
		{
			Hex* hex = this->getHexOnCoord(Coord(i, j));
			if(hex->getSpaceObjectType() == type)
			{
				objects.push_back(Coord(i, j));
			}
		}
	}
	return objects;
}

Coords GameMapImpl::getFleets()
{
	Coords fleets = Coords();
	for (int i = 0; i < dimensions.x; ++i)
	{
		for (int j = 0; j < dimensions.y; ++j)
		{
			Hex* hex = this->getHexOnCoord(Coord(i, j));
			if(hex->hasFleet())
			{
				fleets.push_back(Coord(i, j));
			}
		}
	}
	return fleets;
}

Coords GameMapImpl::getTrail(Coord source, Coord destination)
{
	Coords trail = Coords();
	int currentX = source.x;
	int currentY = source.y;
	while(true)
	{
		Coord next = this->getNextOnTrail(Coord(currentX, currentY), destination);
		trail.push_back(next);
		currentX = next.x;
		currentY = next.y;
		if(currentX == destination.x && currentY == destination.y)
		{
			break;
		}
	}
	return trail;
}

Coord GameMapImpl::getNextOnTrail(Coord source, Coord destination)
{
	Coord next = Coord(source.x, source.y);
	if(source.x != destination.x)
	{
		if(source.x > destination.x)
		{
			if(source.y % 2 == 0 || source.y == destination.y)
			{
				next.x--;
			}
		}
		else
		{
			if(source.y % 2 > 0 || source.y == destination.y)
			{
				next.x++;
			}
		}
	}
	if(source.y != destination.y)
	{
		if(source.y > destination.y)
		{
			next.y--;
		}
		else
		{
			next.y++;
		}
	}
	return next;
}
