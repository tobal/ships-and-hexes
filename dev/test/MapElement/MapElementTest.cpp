

#include <cppunit/extensions/HelperMacros.h>

#include <string>
#include "MapElement/MapElementFactory.hpp"
#include "MapElement/Ship.hpp"
#include "GameConfig/Player.hpp"
#include "GameConfig/PlayerSettings.hpp"

using namespace CppUnit;
using namespace std;
using namespace MapElement;
using namespace GameConfig;

class MapElementTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( MapElementTest );
    CPPUNIT_TEST(createFighter);
    CPPUNIT_TEST_SUITE_END();

private:
    MapElementFactory* factory;

public:
    void setUp()
    {
    	Player* player = new Player(string("tobal"), WHITE, true);
    	factory = new MapElementFactory(player->getName());
    }
    void tearDown()
    {
    	delete factory;
    }

    void createFighter()
    {
    	MapElement::MapElement* ship = factory->createFighter(10);

    	CPPUNIT_ASSERT(dynamic_cast<Ship*>(ship) != NULL);
    	Fighter* fighter = dynamic_cast<Fighter*>(ship);
    	CPPUNIT_ASSERT(fighter != NULL);
    	CPPUNIT_ASSERT_EQUAL(5, fighter->getBaseSpeed());
    	CPPUNIT_ASSERT_EQUAL(5, fighter->getSpeed());
    	CPPUNIT_ASSERT_EQUAL(5, fighter->getMovePoints());
    	CPPUNIT_ASSERT_EQUAL(10, fighter->getCount());
    	CPPUNIT_ASSERT_EQUAL(string("tobal"), fighter->getPlayerName());

    	delete fighter;
    }
};

