
#ifndef SOUNDCONFIG_HPP_
#define SOUNDCONFIG_HPP_

namespace GlobalConfig
{

class SoundConfig
{
private:
	int soundVolume;

public:
	SoundConfig();
	int getSoundVolume() const;
	void setSoundVolume(const int volume);
};

}

#endif /* SOUNDCONFIG_HPP_ */
