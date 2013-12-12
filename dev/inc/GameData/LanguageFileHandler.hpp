#ifndef LANGUAGEFILEHANDLER_HPP_
#define LANGUAGEFILEHANDLER_HPP_

#include <vector>
#include <string>
#include "GameData/LanguageFile.hpp"

namespace GameData
{

class LanguageFileHandler
{
public:
	LanguageFileHandler() {}
	virtual ~LanguageFileHandler() {}
	virtual std::vector<LanguageFile*>* getListOfLanguageFiles() { return NULL; }
};

}



#endif /* LANGUAGEFILEHANDLER_HPP_ */
