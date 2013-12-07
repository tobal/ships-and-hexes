
#ifndef LANGUAGEFILEMOCK_CPP_
#define LANGUAGEFILEMOCK_CPP_

#include "GameData/LanguageFile.hpp"

class LanguageFileMock : public GameData::LanguageFile
{
public:
	LanguageFileMock(std::string name, std::string path) : GameData::LanguageFile(name, path)	{}
};

#endif /* LANGUAGEFILEMOCK_CPP_ */
