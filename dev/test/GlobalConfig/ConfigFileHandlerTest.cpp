
#include <cppunit/extensions/HelperMacros.h>

#include <fstream>
#include "GlobalConfig/ConfigFileHandler.hpp"

using namespace CppUnit;
using namespace GlobalConfig;
using namespace std;

class ConfigFileHandlerTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( ConfigFileHandlerTest );
    CPPUNIT_TEST(configCanBeSavedToFile);
    CPPUNIT_TEST(configCanBeLoadedFromFile);
    CPPUNIT_TEST_SUITE_END();

private:
    ConfigFileHandler* confFile;
    GlobalSettings settings;
    const char* testFilename;
    string testoutput;

public:
    void setUp()
    {
    	testFilename = "testconfig.cfg";
    	confFile = new ConfigFileHandler(testFilename);

    	settings = GlobalSettings();
    	settings.fullscreen = false;
    	settings.widescreen = true;
    	settings.musicVolume = 100;
    	settings.soundVolume = 42;
    	settings.language = "german";

    	testoutput = string("global : {  fullscreen = false;  widescreen = true;  soundVolume = 42;  musicVolume = 100;  language = \"german\";};");
    }

    void tearDown()
    {
    	delete confFile;
    }

    void configCanBeSavedToFile()
    {
    	confFile->saveSettings(settings);
    	ifstream file(testFilename);
    	CPPUNIT_ASSERT(file);

    	string line, output = string("");
    	while( getline(file, line) )
    	{
    		output.append(line);
    	}
    	CPPUNIT_ASSERT(output.compare(testoutput) == 0);

    	file.close();
    	remove(testFilename);
    }

    void configCanBeLoadedFromFile()
    {
    	confFile->saveSettings(settings);
    	GlobalSettings loadedSettings = confFile->loadSettings();
    	CPPUNIT_ASSERT(settings == loadedSettings);
    	remove(testFilename);
    }
};
