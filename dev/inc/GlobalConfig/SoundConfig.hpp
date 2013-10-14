
#ifndef SOUNDCONFIG_HPP_
#define SOUNDCONFIG_HPP_

namespace GlobalConfig
{

class SoundConfig
{
private:
	int soundVolume;
	int musicVolume;
	static const int maxVolume = 100;
	static const int minVolume = 0;
	int limitVolume(const int volume) const;

public:
	SoundConfig();
	int getSoundVolume() const;
	void setSoundVolume(const int volume);
	int getMusicVolume() const;
	void setMusicVolume(const int volume);
};

}

#endif /* SOUNDCONFIG_HPP_ */
