
#include <cppunit/extensions/HelperMacros.h>

#include "GlobalConfig/GlobalConfig.hpp"
#include "GlobalConfig/GlobalConfigImpl.hpp"
#include "GlobalConfig/GlobalSettings.hpp"
#include "LanguageFileHandlerMock.cpp"

using namespace CppUnit;
using namespace GlobalConfig;

class GlobalConfigTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( GlobalConfigTest );
    CPPUNIT_TEST(globalSettingsComparisonWorks);
    CPPUNIT_TEST(firstGetGivesBackDefaultSettings);
    CPPUNIT_TEST(setSettingSetsWholeConfig);
    CPPUNIT_TEST(initConfigResetsToDefaults);
    CPPUNIT_TEST_SUITE_END();

private:
    GlobalSettings defaultSettings;
    GlobalSettings differentSettings;
    GlobalConfig::GlobalConfig* globalConf;

public:
    void setUp()
    {
    	globalConf = new GlobalConfigImpl();
    	GameData::LanguageFileHandler* handler = new LanguageFileHandlerMock();
    	globalConf->setLanguageFileHandler(handler);

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

    void initConfigResetsToDefaults()
    {
    	globalConf->setSettings(differentSettings);
    	globalConf->initConfig();
    	GlobalSettings settings = globalConf->getSettings();
    	CPPUNIT_ASSERT(defaultSettings == settings);
    }
};
