
#include <cppunit/extensions/HelperMacros.h>

#include "Gameplay/Turn.hpp"

using namespace CppUnit;
using namespace Gameplay;

class TurnTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( TurnTest );
    CPPUNIT_TEST(canIncreasePopulation);
    CPPUNIT_TEST_SUITE_END();

private:
    Turn* turn;

public:
    void setUp()
    {
    	turn = new Turn();
    }
    void tearDown()
    {
    	delete turn;
    }

    void canIncreasePopulation()
    {
    	CPPUNIT_ASSERT(true);
    }
};
