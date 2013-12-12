
#ifndef CONFIGFILEHANDLER_HPP_
#define CONFIGFILEHANDLER_HPP_

#include <libconfig.hh>
#include <iostream>
#include <fstream>
#include <string>
#include "GlobalConfig/GlobalSettings.hpp"

namespace GlobalConfig
{

class ConfigFileHandler
{
private:
	std::string filename;

	void readConfigFromFile(libconfig::Config& cfg) const;
	GlobalSettings extractConfig(const libconfig::Config& cfg) const;
	void composeConfig(const libconfig::Config& cfg, const GlobalSettings& settings) const;
	void writeConfigToFile(libconfig::Config& cfg) const;

public:
	ConfigFileHandler(std::string filename);
	virtual ~ConfigFileHandler();
	virtual void saveSettings(const GlobalSettings& settings) const;
	virtual GlobalSettings loadSettings() const;
};

}

#endif /* CONFIGFILEHANDLER_HPP_ */
