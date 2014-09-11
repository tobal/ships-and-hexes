
#include <cppunit/extensions/HelperMacros.h>

#include "GameConfig/Player.hpp"
#include "GameMap/GameMapGenerator.hpp"
#include "GameMap/GameMapImpl.hpp"
#include "GameMap/Hex.hpp"
#include "MapElement/MapElementFactory.hpp"
#include "MapElement/Anomaly.hpp"
#include "Empire/Effect/TwinPlanet.hpp"
#include "Empire/CommonTypes.hpp"

using namespace CppUnit;
using namespace std;
using namespace GameMap;
using namespace GameConfig;
using namespace MapElement;
using namespace Empire::Effect;

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
    	MapEffects mapEffects = MapEffects();
    	mapEffects.push_back(TwinPlanet("player1"));
    	Players players = Players();
    	Player player = Player("player1", RED, false);
    	players.push_back(player);
    	GameMapImpl* map = dynamic_cast<GameMapImpl*>(generator->generateMap(Coord(20, 20), 40, players, mapEffects));
    	Coords planetsOfPlayer = map->getPlanetsOfPlayer("player1");
    	GameMap::CircularMapIterator vicinity = map->getCircularIterator(planetsOfPlayer.at(0), 2);
    	bool foundTwinPlanet = false;
    	while(vicinity.hasNext())
    	{
    		Hex* hex = vicinity.next();
    		if(hex->hasSpaceObject() && hex->getSpaceObjectType() == PLANET)
    		{
    			Planet* planet = dynamic_cast<Planet*>(hex->getSpaceObject());
    			CPPUNIT_ASSERT_EQUAL(player.getPlayerConfig()->getHomeworld(), planet->getPlanetType());
    			CPPUNIT_ASSERT_EQUAL(LARGE, planet->getPlanetSize());
    			foundTwinPlanet = false;
    		}
    	}
    	CPPUNIT_ASSERT(foundTwinPlanet);
    }
};
