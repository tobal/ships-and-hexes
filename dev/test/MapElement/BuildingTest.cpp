
#include <cppunit/extensions/HelperMacros.h>

#include "MapElement/Building.hpp"
#include "MapElement/BuildingSlot.hpp"
#include "Empire/CommonTypes.hpp"
#include "Exceptions/CannotBuildException.hpp"

using namespace CppUnit;
using namespace MapElement;

class BuildingTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( BuildingTest );
    CPPUNIT_TEST(buildingOnNotEmptySlotThrowsException);
    CPPUNIT_TEST(buildingPlanetBuildingOnStationSlotThrowsException);
    CPPUNIT_TEST_SUITE_END();

private:
    BuildingSlot* planetSlot;
    BuildingSlot* stationSlot;

public:
    void setUp()
    {
    	planetSlot = new BuildingSlot(PLANET);
    	stationSlot = new BuildingSlot(SPACESTATION);
    }

    void tearDown()
    {
    }

    void buildingOnNotEmptySlotThrowsException()
    {
    	planetSlot->build(RESEARCH_CENTER);
    	CPPUNIT_ASSERT_THROW(planetSlot->build(CITY), CannotBuildException);
    }

    void buildingPlanetBuildingOnStationSlotThrowsException()
    {
    	CPPUNIT_ASSERT_THROW(planetSlot->build(STATION_MODULE_1), CannotBuildException);
    	CPPUNIT_ASSERT_THROW(stationSlot->build(FIGHTER_FACTORY), CannotBuildException);
    }
};
