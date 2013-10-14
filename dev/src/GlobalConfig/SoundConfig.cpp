
#include "GlobalConfig/SoundConfig.hpp"

using namespace GlobalConfig;

SoundConfig::SoundConfig()
{
	soundVolume = 50;
	musicVolume = 50;
}

int SoundConfig::limitVolume(const int volume) const
{
	if(volume > maxVolume)
		return maxVolume;
	if(volume < minVolume)
		return minVolume;
	else
		return volume;
}

int SoundConfig::getSoundVolume() const
{
	return soundVolume;
}

void SoundConfig::setSoundVolume(const int volume)
{
	this->soundVolume = limitVolume(volume);
}

int SoundConfig::getMusicVolume() const
{
	return musicVolume;
}

void SoundConfig::setMusicVolume(const int volume)
{
	this->musicVolume = limitVolume(volume);
}
