
#ifndef LANGUAGECONFIG_HPP_
#define LANGUAGECONFIG_HPP_

#include <vector>
#include "GlobalConfig/Language.hpp"
#include "GameData/LanguageFileHandler.hpp"
#include "GameData/LanguageFile.hpp"
#include "Exceptions/UnknownLanguageException.hpp"

typedef std::vector<GameData::LanguageFile*> LangFiles;

namespace GlobalConfig
{

class LanguageConfig
{
private:
	Language* language;
	std::vector<Language*>* languages;
	GameData::LanguageFileHandler* handler;

	void populateLanguages() const;
	void storeLanguages(LangFiles* files) const;

public:
	LanguageConfig();
	~LanguageConfig();
	std::vector<Language*> getListOfLanguages() const;
	void setLanguage(const std::string& language) throw(UnknownLanguageException);
	std::string getCurrentLangName() const;
	void setLanguageFileHandler(GameData::LanguageFileHandler* handler);
};

}

#endif /* LANGUAGECONFIG_HPP_ */
