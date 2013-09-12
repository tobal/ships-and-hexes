
#include "GlobalConfig/GraphicsConfig.hpp"

GraphicsConfig::GraphicsConfig()
{
	wideScreen = false;
}

bool GraphicsConfig::getWideScreen() const
{
	return wideScreen;
};

void GraphicsConfig::setWideScreen(const bool wideScreen)
{
	this->wideScreen = wideScreen;
}
