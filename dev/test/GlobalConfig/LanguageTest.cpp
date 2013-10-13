#include <cppunit/extensions/HelperMacros.h>

#include "GlobalConfig/Language.hpp"
#include "GameData/LanguageFile.hpp"
#include "LanguageFileMock.cpp"

using namespace CppUnit;
using namespace GlobalConfig;

class LanguageTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( LanguageTest );
    CPPUNIT_TEST(languageNameAndFileAreSetOnInit);
    CPPUNIT_TEST_SUITE_END();

private:
    GameData::LanguageFile* langFile;

public:
    void setUp()
    {
    	langFile = new LanguageFileMock();
    }
    void tearDown() {}

    void languageNameAndFileAreSetOnInit()
    {
    	Language* lang = new Language("", *langFile );
    	CPPUNIT_ASSERT_EQUAL(std::string(""), lang->getLangName());
    }
};
