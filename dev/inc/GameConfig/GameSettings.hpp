
#ifndef GAMESETTINGS_HPP_
#define GAMESETTINGS_HPP_

namespace GameConfig
{

struct GameSettings
{
	int width;
	int height;
	int density;
	bool randomTurns;
	bool tipOfDay;

	inline bool operator==(const GameSettings& rhs) const
	{
		return this->width == rhs.width &&
				this->height == rhs.height &&
				this->density == rhs.density &&
				this->randomTurns == rhs.randomTurns &&
				this->tipOfDay == rhs.tipOfDay;
	}
};

}

#endif /* GAMESETTINGS_HPP_ */
