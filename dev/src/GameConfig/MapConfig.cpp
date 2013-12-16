
#include "GameConfig/MapConfig.hpp"

using namespace GameConfig;

MapConfig::MapConfig() : width(16), height(16), density(40)
{

}

MapConfig::~MapConfig()
{

}

int MapConfig::limitDimension(const int dimension)
{
	if(dimension > maxDimension)
		return maxDimension;
	if(dimension < minDimension)
		return minDimension;
	else
		return dimension;
}

int MapConfig::limitDensity(const int density)
{
	if(density > maxDensity)
		return maxDensity;
	if(density < minDensity)
		return minDensity;
	else
		return density;
}

int MapConfig::getWidth() const
{
	return width;
}

int MapConfig::getHeight() const
{
	return height;
}

int MapConfig::getDensity() const
{
	return density;
}

void MapConfig::setWidth(const int width)
{
	this->width = limitDimension(width);
}

void MapConfig::setHeight(const int height)
{
	this->height = limitDimension(height);
}

void MapConfig::setDensity(const int density)
{
	this->density = limitDensity(density);
}
