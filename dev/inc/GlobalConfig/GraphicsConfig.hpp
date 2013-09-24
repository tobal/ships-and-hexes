
#ifndef GRAPHICSCONFIG_HPP_
#define GRAPHICSCONFIG_HPP_

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
};

#endif /* GRAPHICSCONFIG_HPP_ */
