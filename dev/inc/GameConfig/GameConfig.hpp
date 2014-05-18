
#ifndef GAMECONFIG_HPP_
#define GAMECONFIG_HPP_

#include "GameConfig/PlayerSettings.hpp"
#include "GameConfig/GameSettings.hpp"

namespace GameConfig
{

class GameConfig
{
public:
	GameConfig() {}
	virtual ~GameConfig() {}
	virtual void addPlayer(std::string name, PlayerColors color, bool controlledByAI) {}
	virtual int getNumberOfPlayers() const {}
	virtual PlayerSettings getPlayerSettings(const int index) const {}
	virtual void setPlayerSettings(const int index, PlayerSettings settings) {}
	virtual GameSettings getGameSettings() const {}
	virtual void setGameSettings(const GameSettings settings) {}
};

}

#endif /* GAMECONFIG_HPP_ */
