
#include <cppunit/extensions/HelperMacros.h>

#include "GlobalConfig/SoundConfig.hpp"

using namespace CppUnit;
using namespace GlobalConfig;

class SoundConfigTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( SoundConfigTest );
    CPPUNIT_TEST(soundVolumeCanBeSet);
    CPPUNIT_TEST(musicVolumeCanBeSet);
    CPPUNIT_TEST(soundVolumeValueHasBounds);
    CPPUNIT_TEST_SUITE_END();

private:
    SoundConfig* soundConf;

public:
    void setUp()
    {
    	soundConf = new SoundConfig();
    }
    void tearDown() {}

    void soundVolumeCanBeSet()
    {
    	int defaultVolume = 50;
    	int volume = 42;
    	CPPUNIT_ASSERT_EQUAL(defaultVolume, soundConf->getSoundVolume());
    	soundConf->setSoundVolume(volume);
    	CPPUNIT_ASSERT_EQUAL(volume, soundConf->getSoundVolume());
    }

    void musicVolumeCanBeSet()
    {
    	int defaultVolume = 50;
    	int volume = 42;
    	CPPUNIT_ASSERT_EQUAL(defaultVolume, soundConf->getMusicVolume());
    	soundConf->setMusicVolume(volume);
    	CPPUNIT_ASSERT_EQUAL(volume, soundConf->getMusicVolume());
    }

    void soundVolumeValueHasBounds()
    {
    	int min = 0;
    	int max = 100;
    	soundConf->setSoundVolume(max + 5);
    	CPPUNIT_ASSERT_EQUAL(max, soundConf->getSoundVolume());
    	soundConf->setSoundVolume(min - 5);
    	CPPUNIT_ASSERT_EQUAL(min, soundConf->getSoundVolume());
    }

    void musicVolumeValueHasBounds()
    {
    	int min = 0;
    	int max = 100;
    	soundConf->setMusicVolume(max + 5);
    	CPPUNIT_ASSERT_EQUAL(max, soundConf->getMusicVolume());
    	soundConf->setMusicVolume(min - 5);
    	CPPUNIT_ASSERT_EQUAL(min, soundConf->getMusicVolume());
    }
};
