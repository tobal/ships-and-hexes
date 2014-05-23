
#include <cppunit/extensions/HelperMacros.h>

#include <string>
#include "MapElement/MapElementFactory.hpp"
#include "MapElement/Ship.hpp"
#include "GameConfig/Player.hpp"
#include "GameConfig/PlayerSettings.hpp"
#include <Empire/Effect/PopulationBonus.hpp>

using namespace CppUnit;
using namespace std;
using namespace MapElement;
using namespace GameConfig;

class MapElementTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( MapElementTest );
    CPPUNIT_TEST(createFighter);
    CPPUNIT_TEST(createBomber);
    CPPUNIT_TEST(createColonizer);
    CPPUNIT_TEST(createPlanet);
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

    void createBomber()
    {
    	MapElement::MapElement* ship = factory->createBomber(10);

    	CPPUNIT_ASSERT(dynamic_cast<Ship*>(ship) != NULL);
    	Bomber* bomber = dynamic_cast<Bomber*>(ship);
    	CPPUNIT_ASSERT(bomber != NULL);
    	CPPUNIT_ASSERT_EQUAL(4, bomber->getBaseSpeed());
    	CPPUNIT_ASSERT_EQUAL(4, bomber->getSpeed());
    	CPPUNIT_ASSERT_EQUAL(4, bomber->getMovePoints());
    	CPPUNIT_ASSERT_EQUAL(10, bomber->getCount());
    	CPPUNIT_ASSERT_EQUAL(string("tobal"), bomber->getPlayerName());

    	delete bomber;
    }

    void createColonizer()
    {
    	MapElement::MapElement* ship = factory->createColonizer(10);

    	CPPUNIT_ASSERT(dynamic_cast<Ship*>(ship) != NULL);
    	Colonizer* colonizer = dynamic_cast<Colonizer*>(ship);
    	CPPUNIT_ASSERT(colonizer != NULL);
    	CPPUNIT_ASSERT_EQUAL(3, colonizer->getBaseSpeed());
    	CPPUNIT_ASSERT_EQUAL(3, colonizer->getSpeed());
    	CPPUNIT_ASSERT_EQUAL(3, colonizer->getMovePoints());
    	CPPUNIT_ASSERT_EQUAL(10, colonizer->getCount());
    	CPPUNIT_ASSERT_EQUAL(string("tobal"), colonizer->getPlayerName());

    	delete colonizer;
    }

    void createPlanet()
    {
    	Empire::Effect::PopulationBonus* pobonus = new Empire::Effect::PopulationBonus();
    	MapElement::MapElement* mapelem = factory->createPlanet(DESERT, SMALL, pobonus);
    	Planet* planet = dynamic_cast<Planet*>(mapelem);
    	CPPUNIT_ASSERT(planet != NULL);
    	CPPUNIT_ASSERT_EQUAL(DESERT, planet->getPlanetType());
    	CPPUNIT_ASSERT_EQUAL(SMALL, planet->getPlanetSize());
    	Empire::Effect::Effect* trait = planet->getPlanetTrait();
    	CPPUNIT_ASSERT(dynamic_cast<Empire::Effect::PopulationBonus*>(trait) != NULL);
    	CPPUNIT_ASSERT_EQUAL(string("tobal"), planet->getPlayerName());
    }
};
