
#include <cppunit/extensions/HelperMacros.h>

#include "GameConfig/SessionConfig.hpp"

using namespace CppUnit;
using namespace GameConfig;

class SessionConfigTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( SessionConfigTest );
    CPPUNIT_TEST(testDefaultValues);
    CPPUNIT_TEST(settingsCanBeSet);
    CPPUNIT_TEST_SUITE_END();

private:
    SessionConfig* sessionConf;

public:
    void setUp()
    {
    	sessionConf = new SessionConfig();
    }
    void tearDown()
    {
    	delete sessionConf;
    }

    void testDefaultValues()
    {
        CPPUNIT_ASSERT_EQUAL(sessionConf->getRandomTurns(), false);
        CPPUNIT_ASSERT_EQUAL(sessionConf->getTipOfDay(), false);
    }

    void settingsCanBeSet()
    {
    	sessionConf->setRandomTurns(true);
        CPPUNIT_ASSERT_EQUAL(sessionConf->getRandomTurns(), true);
        sessionConf->setTipOfDay(true);
        CPPUNIT_ASSERT_EQUAL(sessionConf->getTipOfDay(), true);
    }
};
