
#include <cppunit/extensions/HelperMacros.h>

#include "GameConfig/Player.hpp"
#include "GameMap/GameMapGenerator.hpp"
#include "GameMap/GameMapImpl.hpp"
#include "GameMap/Hex.hpp"
#include "MapElement/MapElementFactory.hpp"
#include "MapElement/Anomaly.hpp"
#include "Empire/CommonTypes.hpp"

using namespace CppUnit;
using namespace std;
using namespace GameMap;
using namespace GameConfig;
using namespace MapElement;

class GameMapGeneratorTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( GameMapGeneratorTest );
    CPPUNIT_TEST(canGenerateEmptyGameMap);
    CPPUNIT_TEST(canPlaceNewRandomAnomaly);
    CPPUNIT_TEST(canGenerateGameMapWithPlanetsAndAnomalies);
    CPPUNIT_TEST(canGenerateGameMapWithPlayers);
    CPPUNIT_TEST(canGenerateGameMapWithEffects);
    CPPUNIT_TEST_SUITE_END();

private:
    GameMapGenerator* generator;

public:
    void setUp()
    {
    	generator = new GameMapGenerator();
    }

    void tearDown()
    {

    }

    int countSpaceObject(MapElementType type, GameMap::GameMap* map)
    {
    	Coord dimensions = map->getDimensions();
    	int count = 0;
    	for (int x = 0; x < dimensions.x; ++x)
    	{
			for (int y = 0; y < dimensions.y; ++y)
			{
				Hex* hex = map->getHexOnCoord(Coord(x, y));
				hex->getSpaceObjectType() == type ? count++ : count;
			}
		}
    	return count;
    }

    void canGenerateEmptyGameMap()
    {
    	GameMap::GameMap* map = generator->generateMap(Coord(20, 20));
    	Coord dimensions = map->getDimensions();
    	for (int x = 0; x < dimensions.x; ++x)
    	{
			for (int y = 0; y < dimensions.y; ++y)
			{
				Hex* hex = map->getHexOnCoord(Coord(x, y));
				CPPUNIT_ASSERT(!hex->hasFleet());
				CPPUNIT_ASSERT(!hex->hasSpaceObject());
			}
		}
    }

    void canPlaceNewRandomAnomaly()
    {
    	int anomaliesPlaced = 5;
    	GameMap::GameMap* map = generator->generateMap(Coord(20, 20));
    	for (int i = 0; i < anomaliesPlaced; ++i) {
        	generator->putRandomAnomaly(map);
		}
    	int anomalyCount = countSpaceObject(ANOMALY, map);
    	CPPUNIT_ASSERT_EQUAL(anomaliesPlaced, anomalyCount);
    }

    void canGenerateGameMapWithPlanetsAndAnomalies()
    {
    	int density = 40;
    	GameMap::GameMap* map = generator->generateMap(Coord(20, 20), density);
    	int planetCount = countSpaceObject(PLANET, map);
    	int anomalyCount = countSpaceObject(ANOMALY, map);
    	CPPUNIT_ASSERT(planetCount >= 46);
    	CPPUNIT_ASSERT_EQUAL(anomalyCount, 24);
    }

    void canGenerateGameMapWithPlayers()
    {
    	Players players = Players();
    	int maxPlayers = 8;
    	for (int i = 0; i < maxPlayers; ++i)
    	{
    		ostringstream playerName;
    		playerName << "player" << i;
    		players.push_back(Player(playerName.str(), RED, false));
		}
    	int density = 40;
    	GameMap::GameMap* map = generator->generateMap(Coord(20, 20), density, players);
    	for (int i = 0; i < maxPlayers; ++i)
		{
			ostringstream playerName;
			playerName << "player" << i;
	    	int planetCount = map->countPlanetsOfPlayer(playerName.str());
	    	CPPUNIT_ASSERT_EQUAL(1, planetCount);
		}
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
};