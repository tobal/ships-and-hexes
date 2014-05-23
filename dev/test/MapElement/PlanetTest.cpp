
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
    CPPUNIT_TEST(canBuildOnPlanet);
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

    void canBuildOnPlanet()
    {
    	planet->build(BOMBER_FACTORY);
    	Buildings* buildings;
    	buildings = planet->getBuildings();
    	for( Buildings::iterator it = buildings->begin(); it != buildings->end(); ++it )
    	{
    		CPPUNIT_ASSERT_EQUAL(BOMBER_FACTORY, (*it)->getType() );
    		vector<BuildingEffect*> effects = (*it)->getEffects();
        	for( vector<BuildingEffect*>::iterator it = effects.begin(); it != effects.end(); ++it )
        	{
            	// TODO: somehow test this
        	}
    	}
    }
};
