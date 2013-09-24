
#ifndef GRAPHICSCONFIG_HPP_
#define GRAPHICSCONFIG_HPP_

namespace GlobalConfig
{

class GraphicsConfig
{
private:
	bool wideScreen;
	bool fullScreen;

public:
	GraphicsConfig();
	bool getWideScreen() const;
	void setWideScreen(const bool wideScreen);
	bool getFullScreen() const;
	void setFullScreen(const bool fullScreen);
};

}

#endif /* GRAPHICSCONFIG_HPP_ */
