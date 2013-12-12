
#include <libconfig.hh>
#include <iostream>
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

void ConfigFileHandler::saveSettings(GlobalSettings settings)
{
	Config cfg;

	Setting &root = cfg.getRoot();
	Setting &global = root.add("global", Setting::TypeGroup);

	global.add("fullscreen", Setting::TypeBoolean) = settings.fullscreen;
	global.add("widescreen", Setting::TypeBoolean) = settings.widescreen;
	global.add("soundVolume", Setting::TypeInt) = settings.soundVolume;
	global.add("musicVolume", Setting::TypeInt) = settings.musicVolume;
	global.add("language", Setting::TypeString) = settings.language.c_str();

	try
	{
		cfg.writeFile(filename.c_str());
	}
	catch(const FileIOException &fioex)
	{
		cerr << "I/O error while writing configuration: " << fioex.what() << endl;
	}
}
