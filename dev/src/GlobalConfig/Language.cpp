
#include "GlobalConfig/Language.hpp"

using namespace GlobalConfig;

Language::Language(const std::string languageName, GameData::LanguageFile* languageFile)
		: languageName(languageName), languageFile(languageFile)
{

}

Language::Language(const char* languageName, GameData::LanguageFile* languageFile)
{
	Language(std::string(languageName), languageFile);
}

Language::~Language()
{
	// TODO: delete languagefile
//	if(languageFile != NULL)
//		delete languageFile;
}

std::string Language::getLangName() const
{
	return languageName;
}

GameData::LanguageFile* Language::getLangFile() const
{
	return languageFile;
}
