
#include <cppunit/extensions/HelperMacros.h>

#include "GlobalConfig/GraphicsConfig.hpp"

using namespace CppUnit;
using namespace GlobalConfig;

class GraphicsConfigTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( GraphicsConfigTest );
    CPPUNIT_TEST(wideScreenIsFalseAtFirst);
    CPPUNIT_TEST(wideScreenCanBeSet);
    CPPUNIT_TEST(fullScreenIsTrueAtFirst);
    CPPUNIT_TEST(fullScreenCanBeSet);
    CPPUNIT_TEST_SUITE_END();

private:
    GraphicsConfig* graphConf;

public:
    void setUp()
    {
    	graphConf = new GraphicsConfig();
    }
    void tearDown() {}

    void wideScreenIsFalseAtFirst()
    {
        bool wideScr = graphConf->getWideScreen();
        CPPUNIT_ASSERT(!wideScr);
    }

    void wideScreenCanBeSet()
    {
    	graphConf->setWideScreen(true);
    	CPPUNIT_ASSERT(graphConf->getWideScreen());
    	graphConf->setWideScreen(false);
    	CPPUNIT_ASSERT(!graphConf->getWideScreen());
    }

    void fullScreenIsTrueAtFirst()
    {
        bool fullScr = graphConf->getFullScreen();
        CPPUNIT_ASSERT(fullScr);
    }

    void fullScreenCanBeSet()
    {
    	graphConf->setFullScreen(true);
    	CPPUNIT_ASSERT(graphConf->getFullScreen());
    	graphConf->setFullScreen(false);
    	CPPUNIT_ASSERT(!graphConf->getFullScreen());
    }
};
