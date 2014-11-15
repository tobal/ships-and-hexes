
#include <cppunit/extensions/HelperMacros.h>

#include "Empire/EmpireImpl.hpp"
#include "Empire/Effect/EmpireEffect.hpp"
#include "GameMap/GameMap.hpp"
#include "GameMap/GameMapGenerator.hpp"
#include "MapElement/MapElementFactory.hpp"
#include <string>

using namespace CppUnit;
using namespace Empire;
using namespace Empire::Effect;
using namespace GameMap;
using namespace MapElement;
using namespace std;

class EmpireTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( EmpireTest );
    CPPUNIT_TEST(canAggregateEmpireEffects);
    CPPUNIT_TEST_SUITE_END();

private:
    Empire::Empire* empire;
    GameMap::GameMap* map;
	MapElementFactory* factory;

public:
    void setUp()
    {
    	empire = new EmpireImpl();
    	factory = new MapElementFactory("player1");
        GameMapGenerator generator = GameMapGenerator();
    	map = generator.generateMap(Coord(20, 20));
    }
    void tearDown()
    {
    	delete empire;
    	delete map;
    	delete factory;
    }

    void canAggregateEmpireEffects()
    {
    	Anomaly* gas = factory->createAnomaly(GASCLOUD, LITTLE);
    	map->getHexOnCoord(Coord(0, 0))->addSpaceObject(gas);
    	Fleet* gasFleet = factory->createFleet(10, 0, 0);
    	map->getHexOnCoord(Coord(0, 0))->addFleet(gasFleet);

    	Anomaly* asteroid = factory->createAnomaly(ASTEROIDFIELD, BIG);
    	map->getHexOnCoord(Coord(0, 1))->addSpaceObject(asteroid);
    	Fleet* asteroidFleet = factory->createFleet(20, 0, 0);
    	map->getHexOnCoord(Coord(0, 1))->addFleet(asteroidFleet);

    	Anomaly* wreck = factory->createAnomaly(ALIENWRECK, BIG);
    	map->getHexOnCoord(Coord(1, 0))->addSpaceObject(wreck);
    	Fleet* wreckFleet = factory->createFleet(40, 0, 0);
    	map->getHexOnCoord(Coord(1, 0))->addFleet(wreckFleet);

    	EmpireEffects* effects = new EmpireEffects();
    	empire->aggregateEmpireEffectsForPlayer(map, effects, string("player1"));
    	for(EmpireEffects::iterator effect = effects->begin(); effect != effects->end(); ++effect)
    	{
    		PopulationBonus* pop = dynamic_cast<PopulationBonus*>(*effect);
    		if(pop != NULL)
    		{
    	    	CPPUNIT_ASSERT_EQUAL(1.1, pop->getEffectMultiplier());
    	    	continue;
    		}
    		ProductionBonus* prod = dynamic_cast<ProductionBonus*>(*effect);
    		if(prod != NULL)
    		{
    	    	CPPUNIT_ASSERT_EQUAL(1.2, prod->getEffectMultiplier());
    	    	continue;
    		}
    		ResearchBonus* res = dynamic_cast<ResearchBonus*>(*effect);
    		if(res != NULL)
    		{
    	    	CPPUNIT_ASSERT_EQUAL(1.4, res->getEffectMultiplier());
    	    	continue;
    		}
    		CPPUNIT_ASSERT(false);
    	}
    }
};
