
#ifndef GLOBALSETTINGS_HPP_
#define GLOBALSETTINGS_HPP_

#include <string>

namespace GlobalConfig
{

struct GlobalSettings
{
	int soundVolume;
	int musicVolume;
	bool widescreen;
	bool fullscreen;
	std::string language;

	inline bool operator==(const GlobalSettings& rhs) const
	{
		return this->soundVolume == rhs.soundVolume &&
				this->musicVolume == rhs.musicVolume &&
				this->widescreen == rhs.widescreen &&
				this->fullscreen == rhs.fullscreen &&
				language.compare(rhs.language) == 0;
	}
};

}

#endif /* GLOBALSETTINGS_HPP_ */
