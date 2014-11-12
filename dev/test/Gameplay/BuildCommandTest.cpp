
#include <cppunit/extensions/HelperMacros.h>

#include "Gameplay/GameplayImpl.hpp"
#include "Gameplay/Command.hpp"
#include "Gameplay/BuildCommand.hpp"
#include "Gameplay/Turn.hpp"
#include "GameMap/GameMap.hpp"
#include "GameMap/GameMapGenerator.hpp"
#include "MapElement/MapElementFactory.hpp"

using namespace CppUnit;
using namespace Gameplay;
using namespace GameMap;
using namespace MapElement;

class BuildCommandTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( BuildCommandTest );
    CPPUNIT_TEST(canBuildOnPlanetToOneSlot);
    CPPUNIT_TEST(canBuildOnPlanetToAllSlots);
    CPPUNIT_TEST(canDemolishBuilding);
    CPPUNIT_TEST(canBuildOnSpaceStation);
    CPPUNIT_TEST(cannotBuildOnUnapproriateObject);
    CPPUNIT_TEST_SUITE_END();

private:
    GameplayImpl* gameplay;
    GameMap::GameMap* map;
	MapElementFactory* factory1;

public:
    void setUp()
    {
    	gameplay = new GameplayImpl();
    	factory1 = new MapElementFactory("player1");
        GameMapGenerator generator = GameMapGenerator();
    	map = generator.generateMap(Coord(20, 20));
    }
    void tearDown()
    {
    	delete gameplay;
    	delete map;
    	delete factory1;
    }

    void canBuildOnPlanetToOneSlot()
    {
    	Turn turn = Turn();
    	Planet* planet = factory1->createPlanet(WATER, LARGE, NULL);
    	CPPUNIT_ASSERT_EQUAL(4, int(planet->getBuildingSlots()->size()));
    	map->getHexOnCoord(Coord(0, 0))->addSpaceObject(planet);
    	BuildCommand build = BuildCommand(Coord(0, 0), 0, BOMBER_FACTORY);
    	CPPUNIT_ASSERT_EQUAL(BUILDSUCCESSFUL, build.executeCommand(map));
    	Building* building = planet->getBuildingSlots()->at(0)->getBuilding();
    	CPPUNIT_ASSERT_EQUAL(BOMBER_FACTORY, building->getType());
    	CPPUNIT_ASSERT_EQUAL(0, building->getCompletePercent());
    	turn.nextTurn(map);
    	CPPUNIT_ASSERT_EQUAL(25, building->getCompletePercent());
    	turn.nextTurn(map);
    	CPPUNIT_ASSERT_EQUAL(50, building->getCompletePercent());
    	turn.nextTurn(map);
    	CPPUNIT_ASSERT_EQUAL(75, building->getCompletePercent());
    	turn.nextTurn(map);
    	CPPUNIT_ASSERT_EQUAL(100, building->getCompletePercent());
    	turn.nextTurn(map);
    	CPPUNIT_ASSERT_EQUAL(100, building->getCompletePercent());
    	CPPUNIT_ASSERT(building->isComplete());
    	CPPUNIT_ASSERT(planet->getBuildingSlots()->at(0)->isComplete());
    }

    void canBuildOnPlanetToAllSlots()
    {
    	Turn turn = Turn();
    	Planet* planet = factory1->createPlanet(WATER, LARGE, NULL);
    	map->getHexOnCoord(Coord(0, 0))->addSpaceObject(planet);
    	BuildCommand build1 = BuildCommand(Coord(0, 0), 0, BOMBER_FACTORY);
    	BuildCommand build2 = BuildCommand(Coord(0, 0), 1, FIGHTER_FACTORY);
    	BuildCommand build3 = BuildCommand(Coord(0, 0), 2, CITY);
    	BuildCommand build4 = BuildCommand(Coord(0, 0), 3, RESEARCH_CENTER);
    	CPPUNIT_ASSERT_EQUAL(BUILDSUCCESSFUL, build1.executeCommand(map));
    	CPPUNIT_ASSERT_EQUAL(BUILDSUCCESSFUL, build2.executeCommand(map));
    	CPPUNIT_ASSERT_EQUAL(BUILDSUCCESSFUL, build3.executeCommand(map));
    	CPPUNIT_ASSERT_EQUAL(BUILDSUCCESSFUL, build4.executeCommand(map));
    	turn.nextTurn(map);
    	turn.nextTurn(map);
    	turn.nextTurn(map);
    	turn.nextTurn(map);
    	CPPUNIT_ASSERT(planet->getBuildingSlots()->at(0)->isComplete());
    	CPPUNIT_ASSERT(planet->getBuildingSlots()->at(1)->isComplete());
    	CPPUNIT_ASSERT(planet->getBuildingSlots()->at(2)->isComplete());
    	CPPUNIT_ASSERT(planet->getBuildingSlots()->at(3)->isComplete());
    }

    void canDemolishBuilding()
    {
    	Turn turn = Turn();
    	Planet* planet = factory1->createPlanet(WATER, LARGE, NULL);
    	map->getHexOnCoord(Coord(0, 0))->addSpaceObject(planet);
    	BuildCommand build = BuildCommand(Coord(0, 0), 0, BOMBER_FACTORY);
    	CPPUNIT_ASSERT_EQUAL(BUILDSUCCESSFUL, build.executeCommand(map));
    	Building* building = planet->getBuildingSlots()->at(0)->getBuilding();
    	turn.nextTurn(map);
    	turn.nextTurn(map);
    	turn.nextTurn(map);
    	turn.nextTurn(map);

		BuildCommand demolist = BuildCommand(Coord(0, 0), 0, NO_BUILDING);
		CPPUNIT_ASSERT_EQUAL(DEMOLISTSUCCESSFUL, demolist.executeCommand(map));
		CPPUNIT_ASSERT_EQUAL(NO_BUILDING, building->getType());
		CPPUNIT_ASSERT_EQUAL(0, building->getCompletePercent());
		CPPUNIT_ASSERT(!building->isComplete());
    }

    void canBuildOnSpaceStation()
    {
    	Turn turn = Turn();
    	SpaceStation* station = factory1->createStation();
    	map->getHexOnCoord(Coord(0, 0))->addSpaceObject(station);
    	BuildCommand build = BuildCommand(Coord(0, 0), 0, STATION_MODULE_1);
    	CPPUNIT_ASSERT_EQUAL(BUILDSUCCESSFUL, build.executeCommand(map));
    	Building* building = station->getBuildingSlot()->getBuilding();
    	CPPUNIT_ASSERT_EQUAL(STATION_MODULE_1, building->getType());
    	turn.nextTurn(map);
    	CPPUNIT_ASSERT_EQUAL(25, building->getCompletePercent());
    	turn.nextTurn(map);
    	turn.nextTurn(map);
    	turn.nextTurn(map);
		CPPUNIT_ASSERT(building->isComplete());
    }

    void cannotBuildOnUnapproriateObject()
    {
    	SpaceStation* station = factory1->createStation();
    	map->getHexOnCoord(Coord(0, 0))->addSpaceObject(station);
    	Planet* planet = factory1->createPlanet(WATER, LARGE, NULL);
    	map->getHexOnCoord(Coord(0, 1))->addSpaceObject(planet);
    	BuildCommand build1 = BuildCommand(Coord(0, 0), 0, BOMBER_FACTORY);
    	BuildCommand build2 = BuildCommand(Coord(0, 1), 0, STATION_MODULE_1);
    	CPPUNIT_ASSERT_THROW(build1.executeCommand(map), CannotBuildException);
    	CPPUNIT_ASSERT_THROW(build2.executeCommand(map), CannotBuildException);
    }
};
