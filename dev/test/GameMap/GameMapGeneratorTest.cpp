
#include <cppunit/extensions/HelperMacros.h>

#include "GameMap/GameMapGenerator.hpp"
#include "GameMap/GameMapImpl.hpp"
#include "GameMap/Hex.hpp"
#include "MapElement/MapElementFactory.hpp"
#include "MapElement/Anomaly.hpp"
#include "Empire/CommonTypes.hpp"

using namespace CppUnit;
using namespace std;
using namespace GameMap;
using namespace MapElement;

class GameMapGeneratorTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( GameMapGeneratorTest );
    CPPUNIT_TEST(canGenerateEmptyGameMap);
    CPPUNIT_TEST(canGenerateGameMapWithPlanetsAndAnomalies);
    CPPUNIT_TEST(canGenerateGameMapWithPlayers);
    CPPUNIT_TEST(canGenerateGameMapWithEffects);
    CPPUNIT_TEST(canPlaceNewRandomAnomaly);
    CPPUNIT_TEST_SUITE_END();

private:
    GameMapGenerator* generator;
    MapElementFactory *p1Factory, *p2Factory, *p3Factory, *p4Factory;

public:
    void setUp()
    {
    	generator = new GameMapGenerator();
    	p1Factory = new MapElementFactory("player1");
    	p2Factory = new MapElementFactory("player2");
    	p3Factory = new MapElementFactory("player3");
    	p4Factory = new MapElementFactory("player4");
    }

    void tearDown()
    {

    }

    void canGenerateEmptyGameMap()
    {
    	GameMap::GameMap* map = generator->generateMap(Coord(20, 20));
    	Coord* dimensions = map->getDimensions();
    	for (int x = 0; x < dimensions->x; ++x)
    	{
			for (int y = 0; y < dimensions->y; ++y)
			{
				Hex* hex = map->getHexOnCoord(Coord(x, y));
				CPPUNIT_ASSERT(!hex->hasFleet());
				CPPUNIT_ASSERT(!hex->hasSpaceObject());
			}
		}
    }

    void canGenerateGameMapWithPlanetsAndAnomalies()
    {
    	int density = 40;
    	GameMap::GameMap* map = generator->generateMap(Coord(20, 20), density);
    	Coord* dimensions = map->getDimensions();
    	int planetCount = 0;
    	int anomalyCount = 0;
    	for (int x = 0; x < dimensions->x; ++x)
    	{
			for (int y = 0; y < dimensions->y; ++y)
			{
				Hex* hex = map->getHexOnCoord(Coord(x, y));
				hex->getSpaceObjectType() == PLANET ? planetCount++ : planetCount;
				hex->getSpaceObjectType() == ANOMALY ? anomalyCount++ : anomalyCount;
			}
		}
    	CPPUNIT_ASSERT(anomalyCount > 20);
    	CPPUNIT_ASSERT(planetCount > 20);
    }

    void canGenerateGameMapWithPlayers()
    {

    }

    void canGenerateGameMapWithEffects()
    {
    	/*
    	 * generáljunk bolygókat úgy, hogy négyzet alakú részekre osztjuk a térképet,
    	 * és azok közül választunk ki egy hexát véletlenszerűen. a részek méretével
    	 * és a részeken belül elhelyezett bolygók számával lehet állítani a sűrűséget
    	 */

    	/*
    	 * az effekteknek lehetnek belépési pontjaik az algoritmusba, template method
    	 */
    }

    void canPlaceNewRandomAnomaly()
    {

    }
};
