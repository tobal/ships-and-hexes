
#include <cppunit/extensions/HelperMacros.h>

#include "GameMap/Fleet.hpp"

using namespace CppUnit;
using namespace std;
using namespace GameMap;

class FleetTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( FleetTest );
    CPPUNIT_TEST(canGetFleetCount);
    CPPUNIT_TEST_SUITE_END();

private:
    Fleet* fleet;

public:
    void setUp()
    {
    	fleet = new Fleet(30, 20, 10);
    }

    void tearDown()
    {
    	delete fleet;
    }

    void canGetFleetCount()
    {
    	FleetCount flc = fleet->getFleetCount();
    	CPPUNIT_ASSERT_EQUAL(30, flc.fighters);
    	CPPUNIT_ASSERT_EQUAL(20, flc.bombers);
    	CPPUNIT_ASSERT_EQUAL(10, flc.colonizers);
    }
};

