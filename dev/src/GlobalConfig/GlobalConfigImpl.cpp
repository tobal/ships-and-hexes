
#include "GlobalConfig/GlobalConfigImpl.hpp"

using namespace GlobalConfig;

void GlobalConfigImpl::initializeBasicConfig() {
	graphConf = new GraphicsConfig();
	soundConf = new SoundConfig();
}

GlobalConfigImpl::GlobalConfigImpl()
{
	initializeBasicConfig();
	langConf = new LanguageConfig();
	confFile = new ConfigFileHandler();
}

GlobalConfigImpl::GlobalConfigImpl(ConfigFileHandler* confHandler)
{
	initializeBasicConfig();
	langConf = new LanguageConfig();
	confFile = confHandler;
}

GlobalConfigImpl::GlobalConfigImpl(GameData::LanguageFileHandler* langHandler)
{
	initializeBasicConfig();
	langConf = new LanguageConfig(langHandler);
	confFile = new ConfigFileHandler();
}

GlobalConfigImpl::GlobalConfigImpl(GameData::LanguageFileHandler* langHandler, ConfigFileHandler* confHandler)
{
	initializeBasicConfig();
	langConf = new LanguageConfig(langHandler);
	confFile = confHandler;
}

GlobalConfigImpl::~GlobalConfigImpl()
{
	delete graphConf;
	delete soundConf;
	delete langConf;
	delete confFile;
}

GlobalSettings GlobalConfigImpl::getSettings() const
{
	GlobalSettings settings = GlobalSettings();
	settings.fullscreen = graphConf->getFullScreen();
	settings.widescreen = graphConf->getWideScreen();
	settings.soundVolume = soundConf->getSoundVolume();
	settings.musicVolume = soundConf->getMusicVolume();
	// FIXME: this is a very ugly hack, make a fix ASAP
	if (langConf->getCurrentLangName() == "")
		settings.language = "english";
	else
		settings.language = langConf->getCurrentLangName();
	return settings;
}

void GlobalConfigImpl::setSettings(const GlobalSettings& settings)
{
	graphConf->setFullScreen(settings.fullscreen);
	graphConf->setWideScreen(settings.widescreen);
	soundConf->setSoundVolume(settings.soundVolume);
	soundConf->setMusicVolume(settings.musicVolume);
	langConf->setLanguage(settings.language);
}
