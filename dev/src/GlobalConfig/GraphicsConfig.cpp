
#include "GlobalConfig/GraphicsConfig.hpp"

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
