#ifndef LANGUAGE_HPP_
#define LANGUAGE_HPP_

#include <string>
#include "GameData/LanguageFile.hpp"

namespace GlobalConfig
{

class Language
{
private:
	std::string languageName;
	GameData::LanguageFile languageFile;

public:
	Language(const std::string languageName, const GameData::LanguageFile& languageFile);
	Language(const char* languageName, const GameData::LanguageFile& languageFile);

	std::string getLangName() const;
	GameData::LanguageFile getLangFile() const;
};

}

#endif /* LANGUAGE_HPP_ */
