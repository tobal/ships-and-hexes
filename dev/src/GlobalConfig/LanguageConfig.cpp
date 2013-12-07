
#include "GlobalConfig/LanguageConfig.hpp"

using namespace GlobalConfig;
using namespace std;

LanguageConfig::LanguageConfig() : language(NULL), handler(NULL)
{
	languages = new vector<Language*>();
}

LanguageConfig::~LanguageConfig()
{
	// TODO: delete all languages
//	for( vector<Language*>::const_iterator it = languages->begin(); it != languages->end(); ++it )
//	{
//		delete *it;
//	}
}

void LanguageConfig::storeLanguages(LangFiles* files) const
{
	for( LangFiles::const_iterator it = files->begin(); it != files->end(); ++it )
	{
		Language* lang = new Language((*it)->getLanguageName(), *it);
		languages->push_back(lang);
	}
}

void LanguageConfig::populateLanguages() const
{
	if( languages->empty() && handler != NULL )
	{
		LangFiles* files = handler->getListOfLanguageFiles();
		storeLanguages(files);
		delete files;
	}
}

vector<Language*> LanguageConfig::getListOfLanguages() const
{
	populateLanguages();
	return *languages;
}

void LanguageConfig::setLanguage(const string& language)
{
	populateLanguages();
	for( vector<Language*>::const_iterator it = languages->begin(); it != languages->end(); ++it )
	{
		if( language.compare((*it)->getLangName()) == 0 )
		{
			this->language = *it;
			return;
		}
	}
	throw UnknownLanguageException();
}

string LanguageConfig::getCurrentLangName() const
{
	return (language != NULL) ? language->getLangName() : NULL;
}

void LanguageConfig::setLanguageFileHandler(GameData::LanguageFileHandler* handler)
{
	this->handler = handler;
}
