
#include <cppunit/extensions/HelperMacros.h>

#include "Gameplay/Turn.hpp"
#include "GameMap/GameMap.hpp"
#include "GameMap/GameMapGenerator.hpp"
#include "MapElement/MapElementFactory.hpp"

using namespace CppUnit;
using namespace Gameplay;
using namespace GameMap;
using namespace MapElement;

class TurnTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( TurnTest );
    CPPUNIT_TEST(canIncreasePopulation);
    CPPUNIT_TEST_SUITE_END();

private:
    Turn* turn;

public:
    void setUp()
    {
    	turn = new Turn();
    }
    void tearDown()
    {
    	delete turn;
    }

    void canIncreasePopulation()
    {
        GameMapGenerator generator = GameMapGenerator();
        GameMap::GameMap* map = generator.generateMap(Coord(20, 20));
    	MapElementFactory* factory = new MapElementFactory("player1");
    	Planet* planet = factory->createPlanet(WATER, LARGE, NULL);
    	map->getHexOnCoord(Coord(0, 0))->addSpaceObject(planet);
    	CPPUNIT_ASSERT_EQUAL(1.0f, planet->getPopulation());
    	turn->nextTurn(map);
    	CPPUNIT_ASSERT_EQUAL(1.1f, planet->getPopulation());
    	turn->nextTurn(map);
    	CPPUNIT_ASSERT_EQUAL(1.2f, planet->getPopulation());
    }
};
