
#ifndef LANGUAGECONFIG_HPP_
#define LANGUAGECONFIG_HPP_

#include <vector>
#include "GlobalConfig/Language.hpp"

namespace GlobalConfig
{

class LanguageConfig
{
private:
	Language* language;

public:
	std::vector<Language*> getListOfLanguages() const;
	void setLanguage(Language* language);
	std::string getCurrentLangName() const;
};

}

#endif /* LANGUAGECONFIG_HPP_ */
