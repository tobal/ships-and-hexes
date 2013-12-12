
#include "GlobalConfig/ConfigFileHandler.hpp"

using namespace GlobalConfig;
using namespace libconfig;
using namespace std;

ConfigFileHandler::ConfigFileHandler(string filename) : filename(filename)
{

}

ConfigFileHandler::~ConfigFileHandler()
{

}

void ConfigFileHandler::composeConfig(const Config& cfg, const GlobalSettings& settings) const
{
	Setting& root = cfg.getRoot();
	Setting& global = root.add("global", Setting::TypeGroup);
	global.add("fullscreen", Setting::TypeBoolean) = settings.fullscreen;
	global.add("widescreen", Setting::TypeBoolean) = settings.widescreen;
	global.add("soundVolume", Setting::TypeInt) = settings.soundVolume;
	global.add("musicVolume", Setting::TypeInt) = settings.musicVolume;
	global.add("language", Setting::TypeString) = settings.language.c_str();
}

void ConfigFileHandler::writeConfigToFile(Config& cfg) const
{
	try
	{
		cfg.writeFile(filename.c_str());
	}
	catch (const FileIOException& fioex)
	{
		cerr << "I/O error while writing configuration: " << fioex.what() << endl;
	}
}

void ConfigFileHandler::readConfigFromFile(Config& cfg) const
{
	try
	{
		cfg.readFile(filename.c_str());
	}
	catch (const FileIOException& fioex)
	{
		cerr << "I/O error while reading file: " << fioex.what() << endl;
	}
	catch (const ParseException& pex)
	{
		cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
				<< " - " << pex.getError() << endl;
	}
}

GlobalSettings ConfigFileHandler::extractConfig(const Config& cfg) const
{
	GlobalSettings settings;
	try
	{
		Setting& root = cfg.getRoot();
		Setting& global = root["global"];
		global.lookupValue("fullscreen", settings.fullscreen);
		global.lookupValue("widescreen", settings.widescreen);
		global.lookupValue("soundVolume", settings.soundVolume);
		global.lookupValue("musicVolume", settings.musicVolume);
		const char* lang;
		global.lookupValue("language", lang);
		settings.language = string(lang);
	}
	catch (const SettingNotFoundException& nfex)
	{
		cerr << "Setting not found in config: " << nfex.getPath() << endl;
	}
	return settings;
}

void ConfigFileHandler::saveSettings(const GlobalSettings& settings) const
{
	Config cfg;
	composeConfig(cfg, settings);
	writeConfigToFile(cfg);
}

GlobalSettings ConfigFileHandler::loadSettings() const
{
	Config cfg;
	readConfigFromFile(cfg);
	GlobalSettings settings = extractConfig(cfg);
	return settings;
}
