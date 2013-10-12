
#include <cppunit/extensions/HelperMacros.h>

#include "GlobalConfig/SoundConfig.hpp"

using namespace CppUnit;
using namespace GlobalConfig;

class SoundConfigTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( SoundConfigTest );
    CPPUNIT_TEST(soundVolumeCanBeSet);
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
};
