
#include <cppunit/extensions/HelperMacros.h>

#include <string>
#include "MapElement/MapElementFactory.hpp"
#include "MapElement/Ship.hpp"
#include "GameConfig/Player.hpp"
#include "GameConfig/PlayerSettings.hpp"
#include "Exceptions/OutOfMovePointsException.hpp"
#include "Exceptions/CannotMergeShipsException.hpp"

using namespace CppUnit;
using namespace std;
using namespace MapElement;
using namespace GameConfig;

class ShipTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( ShipTest );
    CPPUNIT_TEST(shipMoveDecreasesMovePoints);
    CPPUNIT_TEST(movingTooMuchThrowsException);
    CPPUNIT_TEST(thrownExceptionContainsMoveData);
    CPPUNIT_TEST(shipsCanBeAddedAndDestroyed);
    CPPUNIT_TEST(shipMergeChangesMovePointsToMin);
    CPPUNIT_TEST(tooLargeFleetsCannotMerge);
    CPPUNIT_TEST_SUITE_END();

private:
    MapElementFactory* factory;
    Ship* ship;

public:
    void setUp()
    {
    	Player* player = new Player(string("tobal"), WHITE, true);
    	factory = new MapElementFactory(player->getName());
    	ship = factory->createFighter(10);
    }
    void tearDown()
    {
    	delete factory;
    	delete ship;
    }

    void shipMoveDecreasesMovePoints()
    {
    	int toMove = 2;
    	int initialPoints = ship->getMovePoints();
    	ship->move(toMove);
    	CPPUNIT_ASSERT_EQUAL(initialPoints - toMove, ship->getMovePoints());
    }

    void movingTooMuchThrowsException()
    {
    	int initialPoints = ship->getMovePoints();
    	CPPUNIT_ASSERT_NO_THROW(ship->move(initialPoints));
    	CPPUNIT_ASSERT_THROW(ship->move(2), OutOfMovePointsException);
    }

    void thrownExceptionContainsMoveData()
    {
    	int initialPoints = ship->getMovePoints();
    	int plusMoves = 3;
    	try
    	{
    		ship->move(initialPoints + plusMoves);
    	}
    	catch (OutOfMovePointsException& exception)
    	{
    		CPPUNIT_ASSERT_EQUAL(initialPoints, exception.getMoved());
    		CPPUNIT_ASSERT_EQUAL(plusMoves, exception.getMovesRemained());
    	}
    }

    void shipsCanBeAddedAndDestroyed()
    {
    	int initialCount = ship->getCount();
    	ship->addShips(10);
		CPPUNIT_ASSERT_EQUAL(initialCount + 10, ship->getCount());
		ship->destroy(10);
		CPPUNIT_ASSERT_EQUAL(initialCount, ship->getCount());
    }

    void shipMergeChangesMovePointsToMin()
    {
    	int initialPoints = ship->getMovePoints();
    	Fighter* fighterToMerge = factory->createFighter(20);
    	Fighter* fighter = dynamic_cast<Fighter*>(ship);
    	fighter->move(2);
    	fighter->merge(fighterToMerge);
    	delete fighterToMerge;
    	fighterToMerge = NULL;
    	CPPUNIT_ASSERT_EQUAL(initialPoints - 2, fighter->getMovePoints());
    	CPPUNIT_ASSERT_EQUAL(30, fighter->getCount());
    }

    void tooLargeFleetsCannotMerge()
    {
    	Fighter* fighter = dynamic_cast<Fighter*>(ship);
    	Fighter* largeFleet = factory->createFighter(95);
    	CPPUNIT_ASSERT_THROW(fighter->merge(largeFleet), CannotMergeShipsException);
    }
};
