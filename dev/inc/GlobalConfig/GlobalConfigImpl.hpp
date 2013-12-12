
#ifndef GLOBALCONFIGIMPL_HPP_
#define GLOBALCONFIGIMPL_HPP_

#include "GlobalConfig/GlobalConfig.hpp"
#include "GlobalConfig/GlobalSettings.hpp"
#include "GlobalConfig/GraphicsConfig.hpp"
#include "GlobalConfig/SoundConfig.hpp"
#include "GlobalConfig/LanguageConfig.hpp"
#include "GlobalConfig/ConfigFileHandler.hpp"
#include "GameData/LanguageFileHandler.hpp"

namespace GlobalConfig
{

static const std::string confFilename = std::string("defaultfilename");

class GlobalConfigImpl : public GlobalConfig
{
private:
	GraphicsConfig* graphConf;
	SoundConfig* soundConf;
	LanguageConfig* langConf;
	ConfigFileHandler* confFile;

	void initializeBasicConfig();

public:
	GlobalConfigImpl();
	GlobalConfigImpl(ConfigFileHandler* confHandler);
	GlobalConfigImpl(GameData::LanguageFileHandler* langHandler);
	GlobalConfigImpl(GameData::LanguageFileHandler* langHandler, ConfigFileHandler* confHandler);
	~GlobalConfigImpl();
	GlobalSettings getSettings() const;
	void setSettings(const GlobalSettings& settings);
};

}

#endif /* GLOBALCONFIGIMPL_HPP_ */
