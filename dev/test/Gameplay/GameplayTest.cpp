
#include <cppunit/extensions/HelperMacros.h>

#include "Gameplay/GameplayImpl.hpp"
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

    void canMoveFleetAcrossTrail()
    {
//    	Fleet* fleet = factory1->createFleet(10, 5, 1);
//    	map->getHexOnCoord(Coord(0, 0))->addFleet(fleet);
    }

    void canDetectCollisionWhileMoving()
    {

    }
};
