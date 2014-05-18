
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "GameConfig/PlayerSettings.hpp"
#include "PlayerConfig/PlayerConfig.hpp"
#include <string>

namespace GameConfig
{

class Player
{
private:
	PlayerSettings settings;
	PlayerConfig::PlayerConfig* config;

public:
	Player(std::string name, PlayerColors color, bool controlledByAI);
	Player();
	~Player();
	std::string getName() const;
	void setName(const std::string name);
	PlayerColors getColor() const;
	void setColor(const PlayerColors color);
	bool isControlledByAI() const;
	void controlByAI(const bool controlledByAI);
	PlayerConfig::PlayerConfig* getPlayerConfig() const;
};

}

#endif /* PLAYER_HPP_ */
