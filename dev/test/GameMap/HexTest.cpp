
#include <cppunit/extensions/HelperMacros.h>

#include "GameMap/Hex.hpp"
#include "MapElement/Fleet.hpp"
#include "MapElement/MapElementFactory.hpp"
#include "MapElement/Planet.hpp"
#include "MapElement/Anomaly.hpp"
#include "MapElement/SpaceStation.hpp"
#include "Empire/Effect/PopulationBonus.hpp"

using namespace CppUnit;
using namespace std;
using namespace GameMap;
using namespace MapElement;
using namespace Empire::Effect;

class HexTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( HexTest );
    CPPUNIT_TEST(canAddSpaceObjectAndVerifyItsType);
    CPPUNIT_TEST(canGetSpaceObject);
    CPPUNIT_TEST(canRemoveSpaceObject);
    CPPUNIT_TEST(canAddFleet);
    CPPUNIT_TEST(canGetFleet);
    CPPUNIT_TEST(canRemoveFleet);
    CPPUNIT_TEST_SUITE_END();

private:
    Hex* hex;
    MapElementFactory* factory;

    void addFleet()
    {
    	Fleet* fleet = factory->createFleet(30, 20, 10);
    	hex->addFleet(fleet);
    }

public:
    void setUp()
    {
    	hex = new Hex();
    	factory = new MapElementFactory("nobody");
    }

    void tearDown()
    {
    	delete hex;
    	delete factory;
    }

    void canAddSpaceObjectAndVerifyItsType()
    {
    	CPPUNIT_ASSERT( !hex->hasSpaceObject() );
    	Anomaly* anomaly = factory->createAnomaly(ALIENWRECK, LITTLE);
    	hex->addSpaceObject(anomaly);
    	CPPUNIT_ASSERT_EQUAL(ANOMALY, hex->getSpaceObjectType());
    }

    void canGetSpaceObject()
    {
    	PopulationBonus* trait = new PopulationBonus();
    	Planet* planet = factory->createPlanet(DESERT, SMALL, trait);
    	hex->addSpaceObject(planet);
    	Planet* planetOnHex = dynamic_cast<Planet*>(hex->getSpaceObject());
    	CPPUNIT_ASSERT_EQUAL(DESERT, planetOnHex->getPlanetType());
    	CPPUNIT_ASSERT_EQUAL(SMALL, planetOnHex->getPlanetSize());
    }

    void canRemoveSpaceObject()
    {
    	SpaceStation* station = factory->createStation();
    	hex->addSpaceObject(station);
    	CPPUNIT_ASSERT( hex->hasSpaceObject() );
    	hex->removeSpaceObject();
    	CPPUNIT_ASSERT( !hex->hasSpaceObject() );
    }

    void canAddFleet()
    {
    	CPPUNIT_ASSERT( !hex->hasFleet() );
    	addFleet();
    	CPPUNIT_ASSERT( hex->hasFleet() );
    }

    void canGetFleet()
    {
    	addFleet();
    	Fleet* fleetOnHex = hex->getFleet();
    	FleetCount flc = fleetOnHex->getFleetCount();
    	CPPUNIT_ASSERT_EQUAL(30, flc.fighters);
    	CPPUNIT_ASSERT_EQUAL(20, flc.bombers);
    	CPPUNIT_ASSERT_EQUAL(10, flc.colonizers);
    	delete fleetOnHex;
    }

    void canRemoveFleet()
    {
    	addFleet();
    	CPPUNIT_ASSERT( hex->hasFleet() );
    	Fleet* fleetOnHex = hex->moveOutFleet();
    	CPPUNIT_ASSERT_EQUAL(3, fleetOnHex->getMovePoints());
    	CPPUNIT_ASSERT( !hex->hasFleet() );
    	addFleet();
    	hex->destroyFleet();
    	CPPUNIT_ASSERT( !hex->hasFleet() );
    }
};
