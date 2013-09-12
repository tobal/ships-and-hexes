
#ifndef GRAPHICSCONFIG_HPP_
#define GRAPHICSCONFIG_HPP_

class GraphicsConfig
{
private:
	bool wideScreen;

public:
	GraphicsConfig();
	bool getWideScreen() const;
	void setWideScreen(const bool wideScreen);
};

#endif /* GRAPHICSCONFIG_HPP_ */
