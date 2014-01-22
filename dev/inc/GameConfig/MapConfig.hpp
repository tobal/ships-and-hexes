
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

	static const int maxDensity = 90;
	static const int minDensity = 10;
	static const int maxDimension = 32;
	static const int minDimension = 8;

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
	void setSmallMap();
	void setMediumMap();
	void setLargeMap();
	void setRareDensity();
	void setMediumDensity();
	void setDenseDensity();
};

}

#endif /* MAPCONFIG_HPP_ */
