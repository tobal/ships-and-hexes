
#include <cppunit/extensions/HelperMacros.h>

#include "MapElement/Fleet.hpp"
#include "Exceptions/OutOfMovePointsException.hpp"

using namespace CppUnit;
using namespace std;
using namespace MapElement;

class FleetTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( FleetTest );
    CPPUNIT_TEST(canGetFleetCount);
    CPPUNIT_TEST(canAddFleet);
    CPPUNIT_TEST(canRemoveFleet);
    CPPUNIT_TEST(canSplitFleet);
    CPPUNIT_TEST(movePointsCalculatesAfterRemoval);
    CPPUNIT_TEST(addTooManyThrowsException);
    CPPUNIT_TEST(movePointsCalculatesAfterMove);
    CPPUNIT_TEST(resetMovesResetsToSpeed);
    CPPUNIT_TEST_SUITE_END();

private:
    Fleet* fleet;
    MapElementFactory* factory;

public:
    void setUp()
    {
    	factory = new MapElementFactory("player");
    	fleet = factory->createFleet(30, 20, 10);
    }

    void tearDown()
    {
    	delete fleet;
    	delete factory;
    }

    void canGetFleetCount()
    {
    	FleetCount flc = fleet->getFleetCount();
    	CPPUNIT_ASSERT_EQUAL(30, flc.fighters);
    	CPPUNIT_ASSERT_EQUAL(20, flc.bombers);
    	CPPUNIT_ASSERT_EQUAL(10, flc.colonizers);
    }

    void canAddFleet()
    {
    	Fleet* secondFleet = factory->createFleet(10, 10, 5);
    	fleet->mergeFleet(secondFleet);
    	FleetCount flc = fleet->getFleetCount();
    	CPPUNIT_ASSERT_EQUAL(40, flc.fighters);
    	CPPUNIT_ASSERT_EQUAL(30, flc.bombers);
    	CPPUNIT_ASSERT_EQUAL(15, flc.colonizers);
    	delete secondFleet;
    }

    void canRemoveFleet()
    {
    	FleetCount flcRemove = FleetCount(10, 10, 10);
    	fleet->removeFleet(flcRemove);
    	FleetCount flc = fleet->getFleetCount();
    	CPPUNIT_ASSERT_EQUAL(20, flc.fighters);
    	CPPUNIT_ASSERT_EQUAL(10, flc.bombers);
    	CPPUNIT_ASSERT_EQUAL(0, flc.colonizers);
    }

    void canSplitFleet()
    {
    	FleetCount flcSplit = FleetCount(10, 10, 15);
    	Fleet* otherFleet = fleet->splitFleet(flcSplit);
    	FleetCount flc = fleet->getFleetCount();
    	CPPUNIT_ASSERT_EQUAL(20, flc.fighters);
    	CPPUNIT_ASSERT_EQUAL(10, flc.bombers);
    	CPPUNIT_ASSERT_EQUAL(0, flc.colonizers);
    	FleetCount flcOther = otherFleet->getFleetCount();
    	CPPUNIT_ASSERT_EQUAL(10, flcOther.fighters);
    	CPPUNIT_ASSERT_EQUAL(10, flcOther.bombers);
    	CPPUNIT_ASSERT_EQUAL(10, flcOther.colonizers);
    	delete otherFleet;
    }

    void addTooManyThrowsException()
    {
    	Fleet* secondFleet = factory->createFleet(100, 100, 50);
    	CPPUNIT_ASSERT_THROW(fleet->mergeFleet(secondFleet), CannotMergeShipsException);
    	delete secondFleet;
    }

    void movePointsCalculatesAfterRemoval()
    {
    	CPPUNIT_ASSERT_EQUAL(3, fleet->getMovePoints());
    	FleetCount flcRemove = FleetCount(0, 0, 10);
    	fleet->removeFleet(flcRemove);
    	CPPUNIT_ASSERT_EQUAL(4, fleet->getMovePoints());
    	flcRemove = FleetCount(0, 20, 0);
    	fleet->removeFleet(flcRemove);
    	CPPUNIT_ASSERT_EQUAL(5, fleet->getMovePoints());
    	flcRemove = FleetCount(30, 0, 0);
    	fleet->removeFleet(flcRemove);
    	CPPUNIT_ASSERT_EQUAL(0, fleet->getMovePoints());
    }

    void movePointsCalculatesAfterMove()
    {
        Fleet* fleet = factory->createFleet(30, 0, 0);
    	CPPUNIT_ASSERT_EQUAL(5, fleet->getMovePoints());
    	fleet->move(2);
    	CPPUNIT_ASSERT_EQUAL(3, fleet->getMovePoints());
    	fleet->move(1);
    	CPPUNIT_ASSERT_EQUAL(2, fleet->getMovePoints());
    	try
    	{
        	fleet->move(3);
    	}
    	catch (OutOfMovePointsException& e)
    	{
        	CPPUNIT_ASSERT_EQUAL(2, e.getMoved());
    	}
    	CPPUNIT_ASSERT_EQUAL(0, fleet->getMovePoints());
    }

    void resetMovesResetsToSpeed()
    {
    	int speed = fleet->getMovePoints();
    	fleet->move(2);
    	CPPUNIT_ASSERT_EQUAL(1, fleet->getMovePoints());
    	fleet->resetMoves();
    	CPPUNIT_ASSERT_EQUAL(speed, fleet->getMovePoints());
    }
};
