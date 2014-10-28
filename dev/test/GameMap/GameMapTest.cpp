
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
    CPPUNIT_TEST(canGetHexNeighbourCoordinates);
    CPPUNIT_TEST(canItearateWithCircularIterator);
    CPPUNIT_TEST(canGetLargerVicinity);
    CPPUNIT_TEST(canGetVicinityInCorners);
    CPPUNIT_TEST(canCheckIfGivenHexIsCloseToCertainObject);
    CPPUNIT_TEST(canIterateOverDifferentObjectsOverTheMap);
    CPPUNIT_TEST(canGetTrailGivenSourceAndDestination);
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
    	Coord mapDimensions = map->getDimensions();
    	CPPUNIT_ASSERT_EQUAL(16, mapDimensions.x);
    	CPPUNIT_ASSERT_EQUAL(20, mapDimensions.y);
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

    void canGetHexNeighbourCoordinates()
    {
    	Coords coords = map->getCoordNeighbours(Coord(2, 2));
    	CPPUNIT_ASSERT_EQUAL(6, int(coords.size()));
		CPPUNIT_ASSERT(Coord(1, 1) == coords.at(0));
		CPPUNIT_ASSERT(Coord(1, 2) == coords.at(1));
		CPPUNIT_ASSERT(Coord(1, 3) == coords.at(2));
		CPPUNIT_ASSERT(Coord(2, 3) == coords.at(3));
		CPPUNIT_ASSERT(Coord(3, 2) == coords.at(4));
		CPPUNIT_ASSERT(Coord(2, 1) == coords.at(5));

    	coords = map->getCoordNeighbours(Coord(2, 3));
    	CPPUNIT_ASSERT_EQUAL(6, int(coords.size()));
		CPPUNIT_ASSERT(Coord(2, 2) == coords.at(0));
		CPPUNIT_ASSERT(Coord(1, 3) == coords.at(1));
		CPPUNIT_ASSERT(Coord(2, 4) == coords.at(2));
		CPPUNIT_ASSERT(Coord(3, 4) == coords.at(3));
		CPPUNIT_ASSERT(Coord(3, 3) == coords.at(4));
		CPPUNIT_ASSERT(Coord(3, 2) == coords.at(5));

    	coords = map->getCoordNeighbours(Coord(0, 4));
    	CPPUNIT_ASSERT_EQUAL(3, int(coords.size()));
		CPPUNIT_ASSERT(Coord(0, 5) == coords.at(0));
		CPPUNIT_ASSERT(Coord(1, 4) == coords.at(1));
		CPPUNIT_ASSERT(Coord(0, 3) == coords.at(2));
    }

    void canItearateWithCircularIterator()
    {
    	CircularMapIterator itNeighbours = map->getCircularIterator(Coord(2, 1), 1);
    	CPPUNIT_ASSERT(itNeighbours.hasNext());
    	CPPUNIT_ASSERT(Coord(1, 1) == itNeighbours.nextCoord());
    	CPPUNIT_ASSERT(Coord(2, 0) == itNeighbours.nextCoord());
    	CPPUNIT_ASSERT(Coord(2, 2) == itNeighbours.nextCoord());
    	CPPUNIT_ASSERT(Coord(3, 0) == itNeighbours.nextCoord());
    	CPPUNIT_ASSERT(Coord(3, 1) == itNeighbours.nextCoord());
    	CPPUNIT_ASSERT(Coord(3, 2) == itNeighbours.nextCoord());
    	CPPUNIT_ASSERT(!itNeighbours.hasNext());
    }

    void canGetLargerVicinity()
    {
    	CircularMapIterator itAura = map->getCircularIterator(Coord(2, 1), 2);
    	CPPUNIT_ASSERT(itAura.hasNext());
    	CPPUNIT_ASSERT(Coord(0, 1) == itAura.nextCoord());
    	CPPUNIT_ASSERT(Coord(1, 0) == itAura.nextCoord());
    	CPPUNIT_ASSERT(Coord(1, 1) == itAura.nextCoord());
    	CPPUNIT_ASSERT(Coord(1, 2) == itAura.nextCoord());
    	CPPUNIT_ASSERT(Coord(1, 3) == itAura.nextCoord());
    	CPPUNIT_ASSERT(Coord(2, 0) == itAura.nextCoord());
    	CPPUNIT_ASSERT(Coord(2, 2) == itAura.nextCoord());
    	CPPUNIT_ASSERT(Coord(2, 3) == itAura.nextCoord());
    	CPPUNIT_ASSERT(Coord(3, 0) == itAura.nextCoord());
    	CPPUNIT_ASSERT(Coord(3, 1) == itAura.nextCoord());
    	CPPUNIT_ASSERT(Coord(3, 2) == itAura.nextCoord());
    	CPPUNIT_ASSERT(Coord(3, 3) == itAura.nextCoord());
    	CPPUNIT_ASSERT(Coord(4, 0) == itAura.nextCoord());
    	CPPUNIT_ASSERT(Coord(4, 1) == itAura.nextCoord());
    	CPPUNIT_ASSERT(Coord(4, 2) == itAura.nextCoord());
    	CPPUNIT_ASSERT(!itAura.hasNext());
    }

    void canGetVicinityInCorners()
    {
    	CircularMapIterator itTopCorner = map->getCircularIterator(Coord(0, 0), 3);
    	CPPUNIT_ASSERT(itTopCorner.hasNext());
    	CPPUNIT_ASSERT(Coord(0, 1) == itTopCorner.nextCoord());
    	CPPUNIT_ASSERT(Coord(0, 2) == itTopCorner.nextCoord());
    	CPPUNIT_ASSERT(Coord(0, 3) == itTopCorner.nextCoord());
    	CPPUNIT_ASSERT(Coord(1, 0) == itTopCorner.nextCoord());
    	CPPUNIT_ASSERT(Coord(1, 1) == itTopCorner.nextCoord());
    	CPPUNIT_ASSERT(Coord(1, 2) == itTopCorner.nextCoord());
    	CPPUNIT_ASSERT(Coord(1, 3) == itTopCorner.nextCoord());
    	CPPUNIT_ASSERT(Coord(2, 0) == itTopCorner.nextCoord());
    	CPPUNIT_ASSERT(Coord(2, 1) == itTopCorner.nextCoord());
    	CPPUNIT_ASSERT(Coord(2, 2) == itTopCorner.nextCoord());
    	CPPUNIT_ASSERT(Coord(3, 0) == itTopCorner.nextCoord());
    	CPPUNIT_ASSERT(!itTopCorner.hasNext());

    	CircularMapIterator itBottomCorner = map->getCircularIterator(Coord(15, 19), 1);
    	CPPUNIT_ASSERT(itBottomCorner.hasNext());
    	CPPUNIT_ASSERT(Coord(14, 19) == itBottomCorner.nextCoord());
    	CPPUNIT_ASSERT(Coord(15, 18) == itBottomCorner.nextCoord());
    }

    void canCheckIfGivenHexIsCloseToCertainObject()
    {
    	SpaceStation* station = factory->createStation();
    	map->getHexOnCoord(Coord(2, 3))->addSpaceObject(station);
    	CPPUNIT_ASSERT(map->isObjectInVicinity(SPACESTATION, Coord(3, 3), 1));
    	CPPUNIT_ASSERT(!map->isObjectInVicinity(ANOMALY, Coord(3, 3), 1));
    	CPPUNIT_ASSERT(!map->isObjectInVicinity(SPACESTATION, Coord(4, 3), 1));
    	CPPUNIT_ASSERT(map->isObjectInVicinity(SPACESTATION, Coord(4, 3), 2));
    }

    void canIterateOverDifferentObjectsOverTheMap()
    {
    	map->getHexOnCoord(Coord(0, 0))->addSpaceObject(factory->createStation());
    	map->getHexOnCoord(Coord(0, 1))->addSpaceObject(factory->createStation());
    	map->getHexOnCoord(Coord(0, 2))->addSpaceObject(factory->createStation());
    	Coords coords = map->getObjects(SPACESTATION);
    	CPPUNIT_ASSERT(Coord(0, 0) == coords.at(0));
    	CPPUNIT_ASSERT(Coord(0, 1) == coords.at(1));
    	CPPUNIT_ASSERT(Coord(0, 2) == coords.at(2));
    }

    void canGetTrailGivenSourceAndDestination()
    {
    	Coord source = Coord(12, 8);
    	Coord destination = Coord(5, 3);
    	Coords trail = map->getTrail(source, destination);
    	CPPUNIT_ASSERT_EQUAL(9, int(trail.size()));
    	CPPUNIT_ASSERT(Coord(11, 7) == trail.at(0));
    	CPPUNIT_ASSERT(Coord(11, 6) == trail.at(1));
    	CPPUNIT_ASSERT(Coord(10, 5) == trail.at(2));
    	CPPUNIT_ASSERT(Coord(10, 4) == trail.at(3));
    	CPPUNIT_ASSERT(Coord(9, 3) == trail.at(4));
    	CPPUNIT_ASSERT(Coord(8, 3) == trail.at(5));
    	CPPUNIT_ASSERT(Coord(7, 3) == trail.at(6));
    	CPPUNIT_ASSERT(Coord(6, 3) == trail.at(7));
    	CPPUNIT_ASSERT(Coord(5, 3) == trail.at(8));
    }
};
