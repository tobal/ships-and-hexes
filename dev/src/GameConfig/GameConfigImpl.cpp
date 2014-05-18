
#include "GameConfig/GameConfigImpl.hpp"

using namespace GameConfig;
using namespace std;

GameConfigImpl::GameConfigImpl()
{
	players = vector<Player*>();
	mapConf = new MapConfig();
	sessionConf = new SessionConfig();
}

GameConfigImpl::~GameConfigImpl()
{
	delete mapConf;
	delete sessionConf;
	for(vector<Player*>::iterator it = players.begin(); it != players.end(); ++it)
	{
		delete *it;
	}
}

void GameConfigImpl::addPlayer(std::string name, PlayerColors color, bool controlledByAI)
{
	Player* player = new Player(name, color, controlledByAI);
	players.push_back(player);
}

int GameConfigImpl::getNumberOfPlayers() const
{
	return players.size();
}

PlayerSettings GameConfigImpl::getPlayerSettings(const int index) const
{
	PlayerSettings settings = PlayerSettings();
	settings.name = players.at(index)->getName();
	settings.color = players.at(index)->getColor();
	settings.controlledByAI = players.at(index)->isControlledByAI();
	return settings;
}

void GameConfigImpl::setPlayerSettings(const int index, PlayerSettings settings)
{
	Player* player = players.at(index);
	player->setName(settings.name);
	player->setColor(settings.color);
	player->controlByAI(settings.controlledByAI);
}

GameSettings GameConfigImpl::getGameSettings() const
{
	GameSettings settings = GameSettings();
	settings.width = mapConf->getWidth();
	settings.height = mapConf->getHeight();
	settings.density = mapConf->getDensity();
	settings.randomTurns = sessionConf->getRandomTurns();
	settings.tipOfDay = sessionConf->getTipOfDay();
	return settings;
}

void GameConfigImpl::setGameSettings(const GameSettings settings)
{
	mapConf->setWidth(settings.width);
	mapConf->setHeight(settings.height);
	mapConf->setDensity(settings.density);
	sessionConf->setRandomTurns(settings.randomTurns);
	sessionConf->setTipOfDay(settings.tipOfDay);
}
