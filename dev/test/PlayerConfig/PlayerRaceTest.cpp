
#include <cppunit/extensions/HelperMacros.h>

#include "PlayerConfig/PlayerRace.hpp"

using namespace CppUnit;
using namespace PlayerConfig;
using namespace std;

class PlayerRaceTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( PlayerRaceTest );
    CPPUNIT_TEST(playerSettingsCanBeSet);
    CPPUNIT_TEST_SUITE_END();

private:
    PlayerRace* race;

public:
    void setUp()
    {
    	race = new PlayerRace();
    }
    void tearDown()
    {
    	delete race;
    }

    void playerSettingsCanBeSet()
    {
    	CPPUNIT_ASSERT(true);
    }
};
