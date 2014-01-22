
#ifndef PLAYERSETTINGS_HPP_
#define PLAYERSETTINGS_HPP_

#include <string>

namespace GameConfig
{

enum playerColors
{
	WHITE,
	CYAN,
	YELLOW,
	MAGENTA,
	RED,
	GREEN,
	BLUE,
	DARKGREEN,
	ORANGE
};

struct PlayerSettings
{
	std::string name;
	playerColors color;
	bool controlledByAI;
};

}

#endif /* PLAYERSETTINGS_HPP_ */
