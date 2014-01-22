
#include <cppunit/extensions/HelperMacros.h>

#include "GameConfig/MapConfig.hpp"

using namespace CppUnit;
using namespace GameConfig;

class MapConfigTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( MapConfigTest );
    CPPUNIT_TEST(testDefaultValues);
    CPPUNIT_TEST(settingsCanBeSetAndHasBounds);
    CPPUNIT_TEST_SUITE_END();

private:
    MapConfig* mapConf;

public:
    void setUp()
    {
    	mapConf = new MapConfig();
    }
    void tearDown()
    {
    	delete mapConf;
    }

    void testDefaultValues()
    {
    	CPPUNIT_ASSERT_EQUAL(16, mapConf->getWidth());
    	CPPUNIT_ASSERT_EQUAL(16, mapConf->getHeight());
    	CPPUNIT_ASSERT_EQUAL(40, mapConf->getDensity());
    }

    void settingsCanBeSetAndHasBounds()
    {
    	mapConf->setWidth(3);
    	CPPUNIT_ASSERT_EQUAL(8, mapConf->getWidth());
    	mapConf->setHeight(50);
    	CPPUNIT_ASSERT_EQUAL(32, mapConf->getHeight());
    	mapConf->setDensity(5);
    	CPPUNIT_ASSERT_EQUAL(10, mapConf->getDensity());
    	mapConf->setDensity(120);
    	CPPUNIT_ASSERT_EQUAL(90, mapConf->getDensity());
    }
};
