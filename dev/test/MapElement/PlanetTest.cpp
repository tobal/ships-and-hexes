
#include <cppunit/extensions/HelperMacros.h>

#include <string>
#include "MapElement/MapElementFactory.hpp"
#include "MapElement/Planet.hpp"
#include "GameConfig/Player.hpp"
#include "Empire/Effect/PopulationBonus.hpp"
#include "Empire/Effect/BuildingEffect.hpp"

using namespace CppUnit;
using namespace std;
using namespace MapElement;
using namespace GameConfig;
using namespace Empire::Effect;

class PlanetTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( PlanetTest );
    CPPUNIT_TEST(variousSizedPlanetsHaveCorrectBuildingSlots);
    CPPUNIT_TEST(canBuildOnPlanet);
    CPPUNIT_TEST(canDemolishBuilding);
    CPPUNIT_TEST(canGetAndSetPopulation);
    CPPUNIT_TEST_SUITE_END();

private:
    MapElementFactory* factory;
    Planet* planet;

public:
    void setUp()
    {
    	Player* player = new Player(string("tobal"), WHITE, true);
    	factory = new MapElementFactory(player->getName());
    	PopulationBonus* trait = new PopulationBonus();
    	planet = factory->createPlanet(WATER, LARGE, trait);
    }
    void tearDown()
    {
    	delete factory;
    }

    void variousSizedPlanetsHaveCorrectBuildingSlots()
    {
    	PopulationBonus* trait = new PopulationBonus();
    	Planet* smallPlanet = factory->createPlanet(WATER, SMALL, trait);
    	Planet* mediumPlanet = factory->createPlanet(WATER, MEDIUM, trait);
    	Planet* largePlanet = factory->createPlanet(WATER, LARGE, trait);
		CPPUNIT_ASSERT_EQUAL(size_t(2), smallPlanet->getBuildingSlots()->size() );
		CPPUNIT_ASSERT_EQUAL(size_t(3), mediumPlanet->getBuildingSlots()->size() );
		CPPUNIT_ASSERT_EQUAL(size_t(4), largePlanet->getBuildingSlots()->size() );
    }

    void canBuildOnPlanet()
    {
    	BuildingSlots* slots;
    	slots = planet->getBuildingSlots();
    	for( BuildingSlots::iterator slot = slots->begin(); slot != slots->end(); ++slot )
    	{
    		Building* building = (*slot)->getBuilding();
    		CPPUNIT_ASSERT_EQUAL(NO_BUILDING, building->getType() );
    		(*slot)->build(BOMBER_FACTORY);
    		building = (*slot)->getBuilding();
    		CPPUNIT_ASSERT_EQUAL(BOMBER_FACTORY, building->getType() );
    		vector<BuildingEffect*> effects = building->getEffects();
        	for( vector<BuildingEffect*>::iterator it = effects.begin(); it != effects.end(); ++it )
        	{
            	// TODO: somehow test this
        	}
    	}
    }

    void canDemolishBuilding()
    {
    	BuildingSlots* slots;
    	slots = planet->getBuildingSlots();
    	for( BuildingSlots::iterator slot = slots->begin(); slot != slots->end(); ++slot )
    	{
    		(*slot)->build(BOMBER_FACTORY);
    		(*slot)->demolish();
    		Building* building = (*slot)->getBuilding();
    		CPPUNIT_ASSERT_EQUAL(NO_BUILDING, building->getType() );
    	}
    }

    void canGetAndSetPopulation()
    {
    	CPPUNIT_ASSERT_EQUAL(1.0f, planet->getPopulation());
    	planet->setPopulation(4.2f);
    	CPPUNIT_ASSERT_EQUAL(4.2f, planet->getPopulation());
    }
};
