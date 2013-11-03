
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

#include "GlobalConfig/GraphicsConfigTest.cpp"
#include "GlobalConfig/SoundConfigTest.cpp"
#include "GlobalConfig/LanguageTest.cpp"
#include "GlobalConfig/LanguageConfigTest.cpp"

using namespace CppUnit;

int main()
{
    TextUi::TestRunner runner;
    runner.addTest(GraphicsConfigTest::suite());
    runner.addTest(SoundConfigTest::suite());
    runner.addTest(LanguageTest::suite());
    runner.addTest(LanguageConfigTest::suite());
    runner.run();
    return 0;
}
