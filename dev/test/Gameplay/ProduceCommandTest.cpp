
#include <cppunit/extensions/HelperMacros.h>

#include "Gameplay/GameplayImpl.hpp"
#include "Gameplay/Command.hpp"
#include "Gameplay/ProduceCommand.hpp"
#include "Gameplay/Turn.hpp"
#include "GameMap/GameMap.hpp"
#include "GameMap/GameMapGenerator.hpp"
#include "MapElement/MapElementFactory.hpp"
#include <string>

using namespace CppUnit;
using namespace Gameplay;
using namespace GameMap;
using namespace MapElement;
using namespace std;

class ProduceCommandTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( ProduceCommandTest );
    CPPUNIT_TEST(canProduceColonizer);
    CPPUNIT_TEST(produceColonizerFails);
    CPPUNIT_TEST(canProduceColony);
    CPPUNIT_TEST(produceColonyFails);
    CPPUNIT_TEST(canProduceSpaceStation);
    CPPUNIT_TEST(produceSpaceStationFails);
    CPPUNIT_TEST_SUITE_END();

private:
    GameplayImpl* gameplay;
    GameMap::GameMap* map;
	MapElementFactory* factory1;
	MapElementFactory* neutralFactory;

public:
    void setUp()
    {
    	gameplay = new GameplayImpl();
    	factory1 = new MapElementFactory("player1");
    	// TODO: how to indicate a planet is no one's?
    	neutralFactory = new MapElementFactory("nobody");
        GameMapGenerator generator = GameMapGenerator();
    	map = generator.generateMap(Coord(20, 20));
    }
    void tearDown()
    {
    	delete gameplay;
    	delete map;
    	delete factory1;
    	delete neutralFactory;
    }

    void canProduceColonizer()
    {
    	Planet* planet = factory1->createPlanet(WATER, LARGE, NULL);
    	map->getHexOnCoord(Coord(0, 0))->addSpaceObject(planet);
    	planet->setPopulation(2.0f);
    	ProduceCommand produceColonizer = ProduceCommand(Coord(0, 0), COLONIZERPROD);
    	CPPUNIT_ASSERT_EQUAL(PRODUCESUCCESSFUL, produceColonizer.executeCommand(map));
    	CPPUNIT_ASSERT(map->getHexOnCoord(Coord(0, 0))->hasFleet());
    	CPPUNIT_ASSERT_EQUAL(1, map->getHexOnCoord(Coord(0, 0))->getFleet()->getFleetCount().colonizers);
    	CPPUNIT_ASSERT_EQUAL(1.0f, planet->getPopulation());
    }

    void produceColonizerFails()
    {
    	Planet* planet = factory1->createPlanet(WATER, LARGE, NULL);
    	map->getHexOnCoord(Coord(0, 0))->addSpaceObject(planet);
    	planet->setPopulation(1.5f);
    	ProduceCommand produceColonizer = ProduceCommand(Coord(0, 0), COLONIZERPROD);
    	CPPUNIT_ASSERT_EQUAL(PRODUCEFAILED, produceColonizer.executeCommand(map));
    	CPPUNIT_ASSERT(!map->getHexOnCoord(Coord(0, 0))->hasFleet());
    	CPPUNIT_ASSERT_EQUAL(1.5f, planet->getPopulation());
    }

    void canProduceColony()
    {
    	Planet* planet = neutralFactory->createPlanet(WATER, LARGE, NULL);
    	map->getHexOnCoord(Coord(0, 0))->addSpaceObject(planet);
    	Fleet* colonizer = factory1->createFleet(0, 0, 1);
    	map->getHexOnCoord(Coord(0, 0))->addFleet(colonizer);
    	ProduceCommand produceColony = ProduceCommand(Coord(0, 0), COLONYPROD);
    	CPPUNIT_ASSERT_EQUAL(PRODUCESUCCESSFUL, produceColony.executeCommand(map));
    	CPPUNIT_ASSERT(planet->getPlayerName() == string("player1"));
    	CPPUNIT_ASSERT_EQUAL(1.0f, planet->getPopulation());
    	CPPUNIT_ASSERT(!map->getHexOnCoord(Coord(0, 0))->hasFleet());
    }

    void produceColonyFails()
    {
    	Planet* planet = neutralFactory->createPlanet(WATER, LARGE, NULL);
    	map->getHexOnCoord(Coord(0, 0))->addSpaceObject(planet);
    	ProduceCommand produceColony = ProduceCommand(Coord(0, 0), COLONYPROD);
    	CPPUNIT_ASSERT_EQUAL(PRODUCEFAILED, produceColony.executeCommand(map));
    	Fleet* bomber = factory1->createFleet(0, 1, 0);
    	map->getHexOnCoord(Coord(0, 0))->addFleet(bomber);
    	CPPUNIT_ASSERT_EQUAL(PRODUCEFAILED, produceColony.executeCommand(map));
    	CPPUNIT_ASSERT(map->getHexOnCoord(Coord(0, 0))->hasFleet());
    }

    void canProduceSpaceStation()
    {
    	Fleet* colonizer = factory1->createFleet(0, 0, 1);
    	map->getHexOnCoord(Coord(0, 0))->addFleet(colonizer);
    	ProduceCommand produceSpaceStation = ProduceCommand(Coord(0, 0), SPACESTATPROD);
    	CPPUNIT_ASSERT_EQUAL(PRODUCESUCCESSFUL, produceSpaceStation.executeCommand(map));
    	CPPUNIT_ASSERT_EQUAL(SPACESTATION, map->getHexOnCoord(Coord(0, 0))->getSpaceObjectType());
    	CPPUNIT_ASSERT(map->getHexOnCoord(Coord(0, 0))->getSpaceObject()->getPlayerName() == string("player1"));
    	CPPUNIT_ASSERT(!map->getHexOnCoord(Coord(0, 0))->hasFleet());

    }

    void produceSpaceStationFails()
    {
    	ProduceCommand produceSpaceStation = ProduceCommand(Coord(0, 0), SPACESTATPROD);
    	CPPUNIT_ASSERT_EQUAL(PRODUCEFAILED, produceSpaceStation.executeCommand(map));
    	Fleet* colonizer = factory1->createFleet(0, 0, 1);
    	map->getHexOnCoord(Coord(0, 0))->addFleet(colonizer);
    	Planet* planet = neutralFactory->createPlanet(WATER, LARGE, NULL);
    	map->getHexOnCoord(Coord(0, 0))->addSpaceObject(planet);
    	CPPUNIT_ASSERT_EQUAL(PRODUCEFAILED, produceSpaceStation.executeCommand(map));
    	CPPUNIT_ASSERT(map->getHexOnCoord(Coord(0, 0))->hasFleet());

    	map->getHexOnCoord(Coord(0, 0))->removeSpaceObject();
    	SpaceStation* station = neutralFactory->createStation();
    	map->getHexOnCoord(Coord(0, 0))->addSpaceObject(station);
    	CPPUNIT_ASSERT_EQUAL(PRODUCEFAILED, produceSpaceStation.executeCommand(map));
    	CPPUNIT_ASSERT(map->getHexOnCoord(Coord(0, 0))->hasFleet());
    }
};
