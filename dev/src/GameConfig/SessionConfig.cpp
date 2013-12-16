
#include "GameConfig/SessionConfig.hpp"

using namespace GameConfig;

SessionConfig::SessionConfig() : randomTurns(false), tipOfDay(false)
{

}

SessionConfig::~SessionConfig()
{

}

bool SessionConfig::getRandomTurns() const
{
	return randomTurns;
}

bool SessionConfig::getTipOfDay() const
{
	return tipOfDay;
}

void SessionConfig::setRandomTurns(const bool randomTurns)
{
	this->randomTurns = randomTurns;
}

void SessionConfig::setTipOfDay(const bool tipOfDay)
{
	this->tipOfDay = tipOfDay;
}
