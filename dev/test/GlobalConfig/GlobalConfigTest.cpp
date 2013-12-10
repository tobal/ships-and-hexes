
#include <cppunit/extensions/HelperMacros.h>

#include "GlobalConfig/GlobalConfig.hpp"
#include "GlobalConfig/GlobalConfigImpl.hpp"
#include "GlobalConfig/GlobalSettings.hpp"
#include "GlobalConfig/ConfigFileHandler.hpp"
#include "LanguageFileHandlerMock.cpp"
#include "ConfigFileHandlerMock.cpp"

using namespace CppUnit;
using namespace GlobalConfig;

class GlobalConfigTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( GlobalConfigTest );
    CPPUNIT_TEST(globalSettingsComparisonWorks);
    CPPUNIT_TEST(firstGetGivesBackDefaultSettings);
    CPPUNIT_TEST(setSettingSetsWholeConfig);
    CPPUNIT_TEST_SUITE_END();

private:
    GlobalSettings defaultSettings;
    GlobalSettings differentSettings;
    GlobalConfig::GlobalConfig* globalConf;

public:
    void setUp()
    {
    	GameData::LanguageFileHandler* langHandler = new LanguageFileHandlerMock();
    	ConfigFileHandler* confHandler = new ConfigFileHandlerMock();
    	globalConf = new GlobalConfigImpl(langHandler, confHandler);

    	defaultSettings = GlobalSettings();
    	defaultSettings.fullscreen = true;
    	defaultSettings.widescreen = false;
    	defaultSettings.musicVolume = 50;
    	defaultSettings.soundVolume = 50;
    	defaultSettings.language = "english";

    	differentSettings = GlobalSettings();
    	differentSettings.fullscreen = false;
    	differentSettings.widescreen = true;
    	differentSettings.musicVolume = 100;
    	differentSettings.soundVolume = 42;
    	differentSettings.language = "german";
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

    void setSettingSetsWholeConfig()
    {
		globalConf->setSettings(differentSettings);
		GlobalSettings settings = globalConf->getSettings();
		CPPUNIT_ASSERT(differentSettings == settings);
    }
};
