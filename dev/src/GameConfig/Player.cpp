
#include "GameConfig/Player.hpp"
#include "GameConfig/PlayerSettings.hpp"

using namespace GameConfig;
using namespace std;

// TODO: aligence enum instead of controlledByAI

Player::Player(std::string name, PlayerColors color, bool controlledByAI)
{
	settings = PlayerSettings();
	settings.name = name;
	settings.color = color;
	settings.controlledByAI = controlledByAI;
	config = new PlayerConfig::PlayerConfig();
}

Player::Player()
{
	Player(string("Player"), RED, false);
}

Player::~Player()
{
	// TODO delete config (it has something to do with the constructor)
//	delete config;
}

string Player::getName() const
{
	return settings.name;
}

void Player::setName(const std::string name)
{
	settings.name = name;
}

PlayerColors Player::getColor() const
{
	return settings.color;
}

void Player::setColor(const PlayerColors color)
{
	settings.color = color;
}

bool Player::isControlledByAI() const
{
	return settings.controlledByAI;
}

void Player::controlByAI(const bool controlledByAI)
{
	settings.controlledByAI = controlledByAI;
}

PlayerConfig::PlayerConfig* Player::getPlayerConfig() const
{
	return config;
}
