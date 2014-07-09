
#include <cppunit/extensions/HelperMacros.h>

#include "GameMap/GameMapImpl.hpp"

using namespace CppUnit;
using namespace std;
using namespace GameMap;

class GameMapTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( GameMapTest );
    CPPUNIT_TEST(canCreateGameMapGivenDimensions);
    CPPUNIT_TEST_SUITE_END();

private:

public:
    void setUp()
    {
    }

    void tearDown()
    {
    }

    void canCreateGameMapGivenDimensions()
    {
    	GameMapImpl* map = new GameMapImpl(16, 20);
    	Coord* mapDimensions = map->getDimensions();
    	CPPUNIT_ASSERT_EQUAL(16, mapDimensions->x);
    	CPPUNIT_ASSERT_EQUAL(20, mapDimensions->y);
    	delete map;
    }

    void canGetHexOnCoordinates()
    {

    }

    void canGenerateGameMapWithEffects()
    {

    }

    void canIterateOverDifferentObjectsOverTheMap()
    {

    }

    void canGetTrailGivenSourceAndDestination()
    {

    }

    void canMoveFleetAcrossTrail()
    {

    }

    void canDetectCollisionWhileMoving()
    {

    }
};
