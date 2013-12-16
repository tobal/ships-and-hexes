
#ifndef MAPCONFIG_HPP_
#define MAPCONFIG_HPP_

namespace GameConfig
{

class MapConfig
{
private:
	int width;
	int height;
	int density;

	static const int maxDensity = 100;
	static const int minDensity = 0;
	static const int maxDimension = 30;
	static const int minDimension = 5;

	int limitDimension(const int dimension);
	int limitDensity(const int density);

public:
	MapConfig();
	~MapConfig();
	int getWidth() const;
	int getHeight() const;
	int getDensity() const;
	void setWidth(const int width);
	void setHeight(const int height);
	void setDensity(const int density);
};

}

#endif /* MAPCONFIG_HPP_ */
