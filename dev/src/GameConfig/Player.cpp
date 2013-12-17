
#include "GameConfig/Player.hpp"

using namespace GameConfig;
using namespace std;

Player::Player(std::string name, playerColors color, bool controlledByAI)
	: name(name), color(color), controlledByAI(controlledByAI)
{
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
	return name;
}

void Player::setName(const std::string name)
{
	this->name = name;
}

playerColors Player::getColor() const
{
	return color;
}

void Player::setColor(const playerColors color)
{
	this->color = color;
}

bool Player::isControlledByAI() const
{
	return controlledByAI;
}

void Player::controlByAI(const bool controlledByAI)
{
	this->controlledByAI = controlledByAI;
}

PlayerConfig::PlayerConfig* Player::getPlayerConfig() const
{
	return config;
}
