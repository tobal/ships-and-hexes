
#ifndef GLOBALCONFIG_HPP_
#define GLOBALCONFIG_HPP_

#include "GlobalConfig/GlobalSettings.hpp"
#include "GameData/LanguageFileHandler.hpp"

namespace GlobalConfig
{

class GlobalConfig
{
public:
	GlobalConfig() {}
	virtual ~GlobalConfig() {}
	virtual void initConfig() = 0;
	virtual GlobalSettings getSettings() const = 0;
	virtual void setSettings(const GlobalSettings& settings) = 0;
	virtual void setLanguageFileHandler(GameData::LanguageFileHandler* handler) = 0;
};

}

#endif /* GLOBALCONFIG_HPP_ */
