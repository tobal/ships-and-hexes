
#include <cppunit/extensions/HelperMacros.h>

#include "GlobalConfig/GlobalConfig.hpp"
#include "GlobalConfig/GlobalConfigImpl.hpp"
#include "GlobalConfig/GlobalSettings.hpp"

using namespace CppUnit;
using namespace GlobalConfig;

class GlobalConfigTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( GlobalConfigTest );
    CPPUNIT_TEST(globalSettingsComparisonWorks);
    CPPUNIT_TEST(firstGetGivesBackDefaultSettings);
    CPPUNIT_TEST_SUITE_END();

private:
    GlobalSettings defaultSettings;
    GlobalConfig::GlobalConfig* globalConf;

public:
    void setUp()
    {
    	globalConf = new GlobalConfigImpl();

    	defaultSettings = GlobalSettings();
    	defaultSettings.fullscreen = true;
    	defaultSettings.widescreen = false;
    	defaultSettings.musicVolume = 50;
    	defaultSettings.soundVolume = 50;
    	defaultSettings.language = "english";
    }
    void tearDown()
    {
    	delete globalConf;
    }

    void globalSettingsComparisonWorks()
    {
    	GlobalSettings settings = GlobalSettings();
    	settings.fullscreen = true;
    	settings.widescreen = false;
    	settings.musicVolume = 50;
    	settings.soundVolume = 50;
    	settings.language = "english";
    	CPPUNIT_ASSERT(defaultSettings == settings);
    }

    void firstGetGivesBackDefaultSettings()
    {
    	GlobalSettings settings = globalConf->getSettings();
    	CPPUNIT_ASSERT(defaultSettings == settings);
    }
};
