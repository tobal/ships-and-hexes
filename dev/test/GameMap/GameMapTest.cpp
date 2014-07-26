
#include <cppunit/extensions/HelperMacros.h>

#include "GameMap/GameMapImpl.hpp"
#include "GameMap/Hex.hpp"
#include "MapElement/MapElementFactory.hpp"
#include "MapElement/Anomaly.hpp"
#include "Empire/CommonTypes.hpp"

using namespace CppUnit;
using namespace std;
using namespace GameMap;
using namespace MapElement;

class GameMapTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( GameMapTest );
    CPPUNIT_TEST(canCreateGameMapGivenDimensions);
    CPPUNIT_TEST(canGetHexOnCoordinates);
    CPPUNIT_TEST_SUITE_END();

private:
    GameMapImpl* map;
    MapElementFactory* factory;

public:
    void setUp()
    {
    	map = new GameMapImpl(16, 20);
    	factory = new MapElementFactory("nobody");
    }

    void tearDown()
    {
    }

    void canCreateGameMapGivenDimensions()
    {
    	Coord* mapDimensions = map->getDimensions();
    	CPPUNIT_ASSERT_EQUAL(16, mapDimensions->x);
    	CPPUNIT_ASSERT_EQUAL(20, mapDimensions->y);
    	delete map;
    }

    void canGetHexOnCoordinates()
    {
    	Hex* hex = map->getHexOnCoord(Coord(2, 3));
    	Anomaly* anomaly = factory->createAnomaly(GASCLOUD, BIG);
    	hex->addSpaceObject(anomaly);
    	hex = map->getHexOnCoord(Coord(2, 3));
    	CPPUNIT_ASSERT_EQUAL(ANOMALY, hex->getSpaceObjectType());
    }

    void canGenerateGameMapWithEffects()
    {
    	/*
    	 * generáljunk bolygókat úgy, hogy négyzet alakú részekre osztjuk a térképet,
    	 * és azok közül választunk ki egy hexát véletlenszerűen. a részek méretével
    	 * és a részeken belül elhelyezett bolygók számával lehet állítani a sűrűséget
    	 */

    	/*
    	 * az effekteknek lehetnek belépési pontjaik az algoritmusba, template method
    	 */
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
