
#include "GlobalConfig/LanguageConfig.hpp"

using namespace GlobalConfig;
using namespace std;

std::vector<Language>* LanguageConfig::getListOfLanguages() const
{
	vector<Language>* langList = new vector<Language>();
	return langList;
}

void LanguageConfig::setLanguage(const Language& language)
{
	this->language = language;
}

std::string LanguageConfig::getCurrentLangName() const
{
	return language.getLangName();
}
