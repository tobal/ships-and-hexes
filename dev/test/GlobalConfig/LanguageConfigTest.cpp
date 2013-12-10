#include <cppunit/extensions/HelperMacros.h>

#include "GlobalConfig/LanguageConfig.hpp"
#include "GlobalConfig/Language.hpp"
#include "LanguageFileHandlerMock.cpp"
#include "LanguageFileMock.cpp"
#include "Exceptions/UnknownLanguageException.hpp"

using namespace CppUnit;
using namespace GlobalConfig;

class LanguageConfigTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( LanguageConfigTest );
    CPPUNIT_TEST(setLanguageSetsCurrentLanguage);
    CPPUNIT_TEST(gettingListPopulatesLanguageList);
    CPPUNIT_TEST(throwExceptionIfLangIsNotInList);
    CPPUNIT_TEST_SUITE_END();

private:
    GameData::LanguageFile* langFile;
    LanguageConfig* langConf;

public:
    void setUp()
    {
    	langFile = new LanguageFileMock("", "");
    	langConf = new LanguageConfig();

    	GameData::LanguageFileHandler* handler = new LanguageFileHandlerMock();
    	langConf->setLanguageFileHandler(handler);
    }
    void tearDown()
    {
    	delete langConf;
    }

    void setLanguageSetsCurrentLanguage()
    {
    	std::string english = std::string("english");
    	langConf->setLanguage(english);
    	CPPUNIT_ASSERT_EQUAL(english, langConf->getCurrentLangName());
    }

    void gettingListPopulatesLanguageList()
    {
    	std::vector<Language*> langList = langConf->getListOfLanguages();
    	CPPUNIT_ASSERT_EQUAL(2, int(langList.size()));
    	CPPUNIT_ASSERT_EQUAL(std::string("english"), langList.at(0)->getLangName());
    }

    void throwExceptionIfLangIsNotInList()
    {
    	std::string knownLang = std::string("english");
    	CPPUNIT_ASSERT_NO_THROW(langConf->setLanguage(knownLang));
    	CPPUNIT_ASSERT_EQUAL(knownLang, langConf->getCurrentLangName());
    	std::string unknownLang = std::string("hungarian");
    	CPPUNIT_ASSERT_THROW(langConf->setLanguage(unknownLang), UnknownLanguageException);
    }
};
