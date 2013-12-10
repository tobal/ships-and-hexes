
#include "GlobalConfig/GlobalConfigImpl.hpp"

using namespace GlobalConfig;

GlobalConfigImpl::GlobalConfigImpl()
{
	initConfig();
}

GlobalConfigImpl::~GlobalConfigImpl()
{
	clearConfig();
}

void GlobalConfigImpl::initConfig()
{
	// TODO: delete old references
	graphConf = new GraphicsConfig();
	soundConf = new SoundConfig();
	langConf = new LanguageConfig();
}

void GlobalConfigImpl::clearConfig()
{
	delete graphConf;
	delete soundConf;
	delete langConf;
}

GlobalSettings GlobalConfigImpl::getSettings() const
{
	GlobalSettings settings = GlobalSettings();
	settings.fullscreen = graphConf->getFullScreen();
	settings.widescreen = graphConf->getWideScreen();
	settings.soundVolume = soundConf->getSoundVolume();
	settings.musicVolume = soundConf->getMusicVolume();
	// FIXME: this is a very ugly hack, make a fix immediately
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

void GlobalConfigImpl::setLanguageFileHandler(GameData::LanguageFileHandler* handler)
{
	langConf->setLanguageFileHandler(handler);
}
