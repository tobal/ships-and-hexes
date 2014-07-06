
#include <cppunit/extensions/HelperMacros.h>

#include "GameMap/GameMapImpl.hpp"

using namespace CppUnit;
using namespace std;
using namespace GameMap;

class GameMapTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( GameMapTest );
    CPPUNIT_TEST(init);
    CPPUNIT_TEST_SUITE_END();

private:

public:
    void setUp()
    {
    }

    void tearDown()
    {
    }

    void init()
    {
    	CPPUNIT_ASSERT(true);
    }
};
