
#ifndef GAMECONFIGIMPL_HPP_
#define GAMECONFIGIMPL_HPP_

#include <vector>
#include "GameConfig/Player.hpp"
#include "GameConfig/GameConfig.hpp"
#include "GameConfig/MapConfig.hpp"
#include "GameConfig/SessionConfig.hpp"
#include "GameConfig/GameSettings.hpp"

namespace GameConfig
{

class GameConfigImpl : public GameConfig
{
private:
	std::vector<Player*> players;
	MapConfig* mapConf;
	SessionConfig* sessionConf;

public:
	GameConfigImpl();
	~GameConfigImpl();
	void addPlayer(std::string name, PlayerColors color, bool controlledByAI);
	int getNumberOfPlayers() const;
	PlayerSettings getPlayerSettings(const int index) const;
	void setPlayerSettings(const int index, PlayerSettings settings);
	GameSettings getGameSettings() const;
	void setGameSettings(const GameSettings settings);
};

}

#endif /* GAMECONFIGIMPL_HPP_ */
