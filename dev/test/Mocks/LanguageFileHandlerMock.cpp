
#ifndef LANGUAGEFILEHANDLERMOCK_CPP_
#define LANGUAGEFILEHANDLERMOCK_CPP_

#include "GameData/LanguageFileHandler.hpp"
#include "GameData/LanguageFile.hpp"

using namespace GameData;
using namespace std;

class LanguageFileHandlerMock : public GameData::LanguageFileHandler
{
public:
	LanguageFileHandlerMock() {}
	~LanguageFileHandlerMock() {}
	vector<LanguageFile*>* getListOfLanguageFiles()
	{
		LanguageFile* eng = new LanguageFile("english", "/path/to/file");
		LanguageFile* ger = new LanguageFile("german", "/path/to/file");
		vector<LanguageFile*>* files = new vector<LanguageFile*>();
		files->push_back(eng);
		files->push_back(ger);
		return files;
	}
};

#endif /* LANGUAGEFILEHANDLERMOCK_CPP_ */
