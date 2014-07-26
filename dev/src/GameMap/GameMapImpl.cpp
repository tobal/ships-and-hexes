
#include "GameMap/GameMapImpl.hpp"

using namespace GameMap;
using namespace std;

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
