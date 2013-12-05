#include <cppunit/extensions/HelperMacros.h>

#include "GlobalConfig/LanguageConfig.hpp"
#include "GlobalConfig/Language.hpp"
#include "LanguageFileMock.cpp"

using namespace CppUnit;
using namespace GlobalConfig;

class LanguageConfigTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( LanguageConfigTest );
    CPPUNIT_TEST(getListOfLanguagesGivesBackVectorOfLanguages);
    CPPUNIT_TEST(setLanguageSetsCurrentLanguage);
    CPPUNIT_TEST_SUITE_END();

private:
    LanguageConfig* langConf;
    GameData::LanguageFile* langFile;
	Language* language;

public:
    void setUp()
    {
    	langConf = new LanguageConfig();
    	langFile = new LanguageFileMock();
    	language = new Language("english", *langFile );
    }
    void tearDown()
    {
    	delete langConf;
    	delete langFile;
    	delete language;
    }

    void getListOfLanguagesGivesBackVectorOfLanguages()
    {
    	std::vector<Language*> langList = langConf->getListOfLanguages();
    }

    void setLanguageSetsCurrentLanguage()
    {
    	langConf->setLanguage(language);
    	CPPUNIT_ASSERT_EQUAL(langConf->getCurrentLangName(), language->getLangName());
    }

    // TODO: new test: throwExceptionIfLangIsNotInList()
    // needs a new custom exception
};
