
#include <cppunit/extensions/HelperMacros.h>

#include "GlobalConfig/GraphicsConfig.hpp"

using namespace CppUnit;

class GraphicsConfigTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( GraphicsConfigTest );
    CPPUNIT_TEST(wideScreenIsFalseAtFirst);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() {}
    void tearDown() {}

    void wideScreenIsFalseAtFirst()
    {
        GraphicsConfig* graphConf = new GraphicsConfig();
        bool wideScr = graphConf->getWideScreen();
        CPPUNIT_ASSERT(!wideScr);
    }
};
