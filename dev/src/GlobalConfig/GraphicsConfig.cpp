
#include "GlobalConfig/GraphicsConfig.hpp"

using namespace GlobalConfig;

GraphicsConfig::GraphicsConfig()
{
	wideScreen = false;
	fullScreen = true;
}

bool GraphicsConfig::getWideScreen() const
{
	return wideScreen;
};

void GraphicsConfig::setWideScreen(const bool wideScreen)
{
	this->wideScreen = wideScreen;
}

bool GraphicsConfig::getFullScreen() const
{
	return fullScreen;
};

void GraphicsConfig::setFullScreen(const bool fullScreen)
{
	this->fullScreen = fullScreen;
}
