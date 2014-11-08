
#include <cppunit/extensions/HelperMacros.h>

#include "Gameplay/GameplayImpl.hpp"

using namespace CppUnit;
using namespace Gameplay;

class GameplayTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( GameplayTest );
    CPPUNIT_TEST(init);
    CPPUNIT_TEST_SUITE_END();

private:
    GameplayImpl* gameplay;

public:
    void setUp()
    {
    	gameplay = new GameplayImpl();
    }
    void tearDown()
    {
    	delete gameplay;
    }

    void init()
    {
    	CPPUNIT_ASSERT(true);
    }
};
