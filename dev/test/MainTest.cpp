
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

#include "GlobalConfig/GraphicsConfigTest.cpp"
#include "GlobalConfig/SoundConfigTest.cpp"
#include "GlobalConfig/LanguageTest.cpp"
#include "GlobalConfig/LanguageConfigTest.cpp"
#include "GlobalConfig/GlobalConfigTest.cpp"
#include "GlobalConfig/ConfigFileHandlerTest.cpp"
#include "GameConfig/SessionConfigTest.cpp"
#include "GameConfig/MapConfigTest.cpp"
#include "GameConfig/PlayerTest.cpp"
#include "GameConfig/GameConfigTest.cpp"
#include "PlayerConfig/PlayerRaceTest.cpp"
#include "PlayerConfig/TraitTest.cpp"
#include "PlayerConfig/RandomizerTest.cpp"
#include "PlayerConfig/PlayerConfigTest.cpp"
#include "Empire/Effect/EffectTest.cpp"
#include "Empire/EmpireTest.cpp"
#include "MapElement/MapElementTest.cpp"
#include "MapElement/ShipTest.cpp"
#include "MapElement/PlanetTest.cpp"
#include "MapElement/BuildingTest.cpp"

using namespace CppUnit;

int main()
{
    TextUi::TestRunner runner;
    runner.addTest(GraphicsConfigTest::suite());
    runner.addTest(SoundConfigTest::suite());
    runner.addTest(LanguageTest::suite());
    runner.addTest(LanguageConfigTest::suite());
    runner.addTest(GlobalConfigTest::suite());
    runner.addTest(ConfigFileHandlerTest::suite());
    runner.addTest(SessionConfigTest::suite());
    runner.addTest(MapConfigTest::suite());
    runner.addTest(PlayerTest::suite());
    runner.addTest(GameConfigTest::suite());
    runner.addTest(PlayerRaceTest::suite());
    runner.addTest(TraitTest::suite());
    runner.addTest(RandomizerTest::suite());
    runner.addTest(PlayerConfigTest::suite());
    runner.addTest(EffectTest::suite());
    runner.addTest(EmpireTest::suite());
    runner.addTest(MapElementTest::suite());
    runner.addTest(ShipTest::suite());
    runner.addTest(PlanetTest::suite());
    runner.addTest(BuildingTest::suite());
    runner.run();
    return 0;
}
