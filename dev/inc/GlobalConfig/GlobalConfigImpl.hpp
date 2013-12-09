
#ifndef GLOBALCONFIGIMPL_HPP_
#define GLOBALCONFIGIMPL_HPP_

#include "GlobalConfig/GlobalConfig.hpp"
#include "GlobalConfig/GlobalSettings.hpp"
#include "GlobalConfig/GraphicsConfig.hpp"
#include "GlobalConfig/SoundConfig.hpp"
#include "GlobalConfig/LanguageConfig.hpp"

namespace GlobalConfig
{

class GlobalConfigImpl : public GlobalConfig
{
private:
	GraphicsConfig* graphConf;
	SoundConfig* soundConf;
	LanguageConfig* langConf;

	void clearConfig();

public:
	GlobalConfigImpl();
	~GlobalConfigImpl();
	void initConfig();
	GlobalSettings getSettings() const;
	void setSettings(const GlobalSettings& settings);
};

}

#endif /* GLOBALCONFIGIMPL_HPP_ */
