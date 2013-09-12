
#include <cppunit/extensions/HelperMacros.h>

#include "GlobalConfig/GraphicsConfig.hpp"

using namespace CppUnit;

class GraphicsConfigTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( GraphicsConfigTest );
    CPPUNIT_TEST(wideScreenIsFalseAtFirst);
    CPPUNIT_TEST(wideScreenCanBeSet);
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
};
