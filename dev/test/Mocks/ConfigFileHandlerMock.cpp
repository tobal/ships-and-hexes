
#ifndef CONFIGFILEHANDLERMOCK_CPP_
#define CONFIGFILEHANDLERMOCK_CPP_

#include "GlobalConfig/ConfigFileHandler.hpp"

using namespace GlobalConfig;

class ConfigFileHandlerMock : public ConfigFileHandler
{
public:
	ConfigFileHandlerMock(const char* filename) : ConfigFileHandler(filename) {}
	~ConfigFileHandlerMock() {}
};

#endif /* CONFIGFILEHANDLERMOCK_CPP_ */
