
#include <cppunit/extensions/HelperMacros.h>

#include "Gameplay/GameplayImpl.hpp"
#include "Gameplay/Command.hpp"
#include "Gameplay/MoveCommand.hpp"
#include "Gameplay/Turn.hpp"
#include "GameMap/GameMap.hpp"
#include "GameMap/GameMapGenerator.hpp"
#include "MapElement/MapElementFactory.hpp"

using namespace CppUnit;
using namespace Gameplay;
using namespace GameMap;
using namespace MapElement;

class GameplayTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( GameplayTest );
    CPPUNIT_TEST(canMoveFleetAcrossTrail);
    CPPUNIT_TEST(mergesWithFleetIfMovedToIt);
    CPPUNIT_TEST(canJumpOverFriendlyFleet);
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

    void assertFleetMoved(Command* moveFleet, Fleet* fleet,
    					  Coord from, Coord to,
    					  CommandResult expectedResult, int expectedMovePoints)
    {
    	CommandResult result = moveFleet->executeCommand(map);
    	CPPUNIT_ASSERT_EQUAL_MESSAGE("Result assert failed", expectedResult, result);
    	CPPUNIT_ASSERT_MESSAGE("From hex assert failed", !map->getHexOnCoord(from)->hasFleet());
    	CPPUNIT_ASSERT_MESSAGE("To hex assert failed", map->getHexOnCoord(to)->hasFleet());
    	CPPUNIT_ASSERT_EQUAL_MESSAGE("MovePoints assert failed", expectedMovePoints, fleet->getMovePoints());
    }

    void canMoveFleetAcrossTrail()
    {
    	Fleet* fleet = factory1->createFleet(10, 5, 1);
    	map->getHexOnCoord(Coord(0, 0))->addFleet(fleet);
    	CPPUNIT_ASSERT_EQUAL(3, fleet->getMovePoints());

    	Command* moveFleet = new MoveCommand(Coord(0, 0), FLEET, Coord(4, 6));
    	this->assertFleetMoved(moveFleet, fleet, Coord(0, 0), Coord(0, 1), MOVEINPROGRESS, 2);
    	this->assertFleetMoved(moveFleet, fleet, Coord(0, 1), Coord(1, 2), MOVEINPROGRESS, 1);
    	this->assertFleetMoved(moveFleet, fleet, Coord(1, 2), Coord(1, 3), OUTOFMOVEPOINTS, 0);
    	fleet->removeFleet(FleetCount(0, 0, 1));
    	Turn turn = Turn();
    	turn.nextTurn(map);
    	CPPUNIT_ASSERT_EQUAL(4, fleet->getMovePoints());
    	this->assertFleetMoved(moveFleet, fleet, Coord(1, 3), Coord(2, 4), MOVEINPROGRESS, 3);
    	this->assertFleetMoved(moveFleet, fleet, Coord(2, 4), Coord(2, 5), MOVEINPROGRESS, 2);
    	this->assertFleetMoved(moveFleet, fleet, Coord(2, 5), Coord(3, 6), MOVEINPROGRESS, 1);
    	this->assertFleetMoved(moveFleet, fleet, Coord(3, 6), Coord(4, 6), DESTINATIONREACHED, 0);

    }

    void mergesWithFleetIfMovedToIt()
    {
    	Fleet* fleet = factory1->createFleet(10, 5, 0);
    	map->getHexOnCoord(Coord(0, 0))->addFleet(fleet);
    	Fleet* fleet2 = factory1->createFleet(10, 5, 0);
    	map->getHexOnCoord(Coord(1, 2))->addFleet(fleet2);

    	Command* moveFleet = new MoveCommand(Coord(0, 0), FLEET, Coord(1, 2));
    	this->assertFleetMoved(moveFleet, fleet, Coord(0, 0), Coord(0, 1), MOVEINPROGRESS, 3);
    	this->assertFleetMoved(moveFleet, fleet, Coord(0, 1), Coord(1, 2), DESTINATIONREACHED, 2);
    	CPPUNIT_ASSERT_EQUAL(20, fleet->getFleetCount().fighters);
    	CPPUNIT_ASSERT_EQUAL(10, fleet->getFleetCount().bombers);
    	CPPUNIT_ASSERT_EQUAL(0, fleet->getFleetCount().colonizers);
    }

    void canJumpOverFriendlyFleet()
    {
		Fleet* fleet = factory1->createFleet(10, 5, 0);
		map->getHexOnCoord(Coord(0, 0))->addFleet(fleet);
		Fleet* fleet2 = factory1->createFleet(40, 15, 5);
		map->getHexOnCoord(Coord(1, 2))->addFleet(fleet2);

		MoveCommand* moveFleet = new MoveCommand(Coord(0, 0), FLEET, Coord(1, 3));
		this->assertFleetMoved(moveFleet, fleet, Coord(0, 0), Coord(0, 1), MOVEINPROGRESS, 3);
		this->assertFleetMoved(moveFleet, fleet, Coord(0, 1), Coord(1, 3), DESTINATIONREACHED, 1);
    }

    void jumpsOverSeveralFriendlyFleets()
    {

    }

    void mergesIntoFriendlyFleetDuringJump()
    {

    }

    void stopsIfCannotMove()
    {
    	Fleet* fleet = factory1->createFleet(10, 5, 1);
    	map->getHexOnCoord(Coord(0, 0))->addFleet(fleet);
    	Fleet* fleet2 = factory1->createFleet(100, 5, 0);
    	map->getHexOnCoord(Coord(1, 2))->addFleet(fleet2);

    	Command* moveFleet = new MoveCommand(Coord(0, 0), FLEET, Coord(4, 6));
    	this->assertFleetMoved(moveFleet, fleet, Coord(0, 0), Coord(0, 1), MOVEINPROGRESS, 2);
    	this->assertFleetMoved(moveFleet, fleet, Coord(0, 1), Coord(1, 2), MOVEINPROGRESS, 1);
    	this->assertFleetMoved(moveFleet, fleet, Coord(0, 1), Coord(1, 2), CANNOTMOVEFURTHER, 1);
    }

    void battleInitiatedIfCollidedWithEnemyFleet()
    {

    }
};
