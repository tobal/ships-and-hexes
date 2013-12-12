
#ifndef CONFIGFILEHANDLER_HPP_
#define CONFIGFILEHANDLER_HPP_

#include <fstream>
#include <string>
#include "GlobalConfig/GlobalSettings.hpp"

namespace GlobalConfig
{

class ConfigFileHandler
{
private:
	std::string filename;

public:
	ConfigFileHandler(std::string filename);
	virtual ~ConfigFileHandler();
	virtual void saveSettings(GlobalSettings settings);
};

}

#endif /* CONFIGFILEHANDLER_HPP_ */
