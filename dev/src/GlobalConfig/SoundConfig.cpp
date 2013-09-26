
#include "GlobalConfig/SoundConfig.hpp"

using namespace GlobalConfig;

SoundConfig::SoundConfig()
{
	soundVolume = 50;
}

int SoundConfig::getSoundVolume() const
{
	return soundVolume;
}

void SoundConfig::setSoundVolume(const int volume)
{
	this->soundVolume = volume;
}
