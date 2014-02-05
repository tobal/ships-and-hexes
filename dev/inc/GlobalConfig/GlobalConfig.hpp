
#ifndef GLOBALCONFIG_HPP_
#define GLOBALCONFIG_HPP_

#include "GlobalConfig/GlobalSettings.hpp"

namespace GlobalConfig
{

class GlobalConfig
{
public:
	GlobalConfig() {}
	virtual ~GlobalConfig() {}
	virtual GlobalSettings getSettings() const = 0;
	virtual void setSettings(const GlobalSettings& settings) = 0;
};

}

#endif /* GLOBALCONFIG_HPP_ */
