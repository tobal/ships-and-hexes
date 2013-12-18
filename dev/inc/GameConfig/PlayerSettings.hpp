
#ifndef PLAYERSETTINGS_HPP_
#define PLAYERSETTINGS_HPP_

#include <string>

namespace GameConfig
{

enum playerColors
{
	RED,
	GREEN,
	BLACK
};

struct PlayerSettings
{
	std::string name;
	playerColors color;
	bool controlledByAI;
};

}

#endif /* PLAYERSETTINGS_HPP_ */
