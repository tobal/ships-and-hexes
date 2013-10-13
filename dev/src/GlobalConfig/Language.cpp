
#include "GlobalConfig/Language.hpp"

using namespace GlobalConfig;

Language::Language(const std::string languageName, const GameData::LanguageFile& languageFile)
		: languageName(languageName), languageFile(languageFile)
{

}

Language::Language(const char* languageName, const GameData::LanguageFile& languageFile)
{
	Language(std::string(languageName), languageFile);
}

std::string Language::getLangName() const
{
	return languageName;
}

GameData::LanguageFile Language::getLangFile() const
{
	return languageFile;
}
