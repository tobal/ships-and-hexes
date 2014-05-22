
#include <cppunit/extensions/HelperMacros.h>

#include <Empire/Effect/ShipBonus.hpp>
#include <Empire/Effect/EffectivenessBonus.hpp>
#include <Empire/Effect/SensePlanetType.hpp>
#include <Empire/Effect/TwinPlanet.hpp>
#include <Empire/Effect/ExtraShips.hpp>
#include <Empire/Effect/ExtraBuildings.hpp>
#include <Empire/Effect/ProductionBonus.hpp>
#include <Empire/Effect/ResearchBonus.hpp>
#include <Empire/Effect/MovementBonus.hpp>
#include <Empire/Effect/PopulationBonus.hpp>
#include <Empire/Effect/BuildingEffect.hpp>

using namespace CppUnit;
using namespace Empire::Effect;

class EffectTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( EffectTest );
    CPPUNIT_TEST(concreteSubclassesCanBeInstantiated);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
    }

    void tearDown()
    {
    }

    void concreteSubclassesCanBeInstantiated()
    {
    	ShipBonus ship = ShipBonus(10);
    	EffectivenessBonus eff = EffectivenessBonus(10);
    	SensePlanetType sense = SensePlanetType();
    	TwinPlanet twin = TwinPlanet();
    	ExtraShips exship = ExtraShips();
    	ExtraBuildings exbuild = ExtraBuildings();
    	ProductionBonus prbonus = ProductionBonus();
    	ResearchBonus rbonus = ResearchBonus();
    	MovementBonus mbonus = MovementBonus();
    	PopulationBonus pobonus = PopulationBonus();
    	BuildingEffect building = BuildingEffect();
    }
};
