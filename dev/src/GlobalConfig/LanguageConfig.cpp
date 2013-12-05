
#include "GlobalConfig/LanguageConfig.hpp"

using namespace GlobalConfig;
using namespace std;

std::vector<Language*> LanguageConfig::getListOfLanguages() const
{
	// TODO: implement method
	vector<Language*> langList = vector<Language*>();
	return langList;
}

void LanguageConfig::setLanguage(Language* language)
{
	this->language = language;
}

std::string LanguageConfig::getCurrentLangName() const
{
	return language->getLangName();
}
