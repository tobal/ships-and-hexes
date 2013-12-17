
#include "GameConfig/Player.hpp"

using namespace GameConfig;
using namespace std;

Player::Player() : name(string("Player")), color(RED), controlledByAI(false)
{

}

Player::~Player()
{

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
