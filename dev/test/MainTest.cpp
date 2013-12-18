
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
    runner.run();
    return 0;
}
