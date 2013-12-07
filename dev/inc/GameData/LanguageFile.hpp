#ifndef LANGUAGEFILE_HPP_
#define LANGUAGEFILE_HPP_

#include <string>

namespace GameData
{

class LanguageFile
{
private:
	std::string name;
	std::string path;

public:
	LanguageFile(std::string name, std::string path) : name(name), path(path) {}
	virtual ~LanguageFile() {}

	std::string getLanguageName() const;
};

}

#endif /* LANGUAGEFILE_HPP_ */
