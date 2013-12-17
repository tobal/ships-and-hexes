
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "PlayerConfig/PlayerConfig.hpp"
#include <string>

namespace GameConfig
{

enum playerColors
{
	RED,
	GREEN,
	BLACK
};

class Player
{
private:
	std::string name;
	playerColors color;
	bool controlledByAI;
	PlayerConfig::PlayerConfig* config;

public:
	Player(std::string name, playerColors color, bool controlledByAI);
	Player();
	~Player();
	std::string getName() const;
	void setName(const std::string name);
	playerColors getColor() const;
	void setColor(const playerColors color);
	bool isControlledByAI() const;
	void controlByAI(const bool controlledByAI);
	PlayerConfig::PlayerConfig* getPlayerConfig() const;
};

}

#endif /* PLAYER_HPP_ */
