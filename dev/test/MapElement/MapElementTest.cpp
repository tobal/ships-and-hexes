

#include <cppunit/extensions/HelperMacros.h>

#include "MapElement/MapElementImpl.hpp"

using namespace CppUnit;
using namespace MapElement;

class MapElementTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( MapElementTest );
    CPPUNIT_TEST(init);
    CPPUNIT_TEST_SUITE_END();

private:
    MapElement::MapElement* mapElement;

public:
    void setUp()
    {
    	mapElement = new MapElementImpl();
    }
    void tearDown()
    {
    	delete mapElement;
    }

    void init()
    {
    	CPPUNIT_ASSERT_EQUAL(1, 1);
    }
};

