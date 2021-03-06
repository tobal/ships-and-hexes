
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
#include "Empire/ResearchTest.cpp"
#include "MapElement/MapElementTest.cpp"
#include "MapElement/ShipTest.cpp"
#include "MapElement/PlanetTest.cpp"
#include "MapElement/BuildingTest.cpp"
#include "MapElement/FleetTest.cpp"
#include "GameMap/HexTest.cpp"
#include "GameMap/GameMapTest.cpp"
#include "GameMap/GameMapGeneratorTest.cpp"
#include "Gameplay/GameplayTest.cpp"
#include "Gameplay/MoveCommandTest.cpp"
#include "Gameplay/BuildCommandTest.cpp"
#include "Gameplay/ProduceCommandTest.cpp"
#include "Gameplay/TurnTest.cpp"

using namespace CppUnit;

int _main()
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
    runner.addTest(FleetTest::suite());
    runner.addTest(HexTest::suite());
    runner.addTest(GameMapTest::suite());
    runner.addTest(GameMapGeneratorTest::suite());
    runner.addTest(GameplayTest::suite());
    runner.addTest(MoveCommandTest::suite());
    runner.addTest(BuildCommandTest::suite());
    runner.addTest(ProduceCommandTest::suite());
    runner.addTest(TurnTest::suite());
    runner.addTest(ResearchTest::suite());
    runner.run();
    return 0;
}
