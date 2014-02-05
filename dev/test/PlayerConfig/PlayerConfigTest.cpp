
#include <cppunit/extensions/HelperMacros.h>

#include "PlayerConfig/PlayerConfigImpl.hpp"
//#include "Empire/CommonTypes.hpp"

using namespace CppUnit;
using namespace PlayerConfig;

class PlayerConfigTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( PlayerConfigTest );
    CPPUNIT_TEST(canModifyBasicPlayerRaceSettings);
    CPPUNIT_TEST_SUITE_END();

private:
    PlayerConfig::PlayerConfig* config;

public:
    void setUp()
    {
    	config = new PlayerConfigImpl();
    }
    void tearDown()
    {
    	delete config;
    }

    void canModifyBasicPlayerRaceSettings()
    {
    	config->setRace(AMAZON);
    	CPPUNIT_ASSERT_EQUAL(AMAZON, config->getRace());
    	config->setHomeworld(LAVA);
    	CPPUNIT_ASSERT_EQUAL(LAVA, config->getHomeworld());
    	config->setCredo(WARMONGER);
    	CPPUNIT_ASSERT_EQUAL(WARMONGER, config->getCredo());
    }

    //canGetAllTraits
    //canSetTraitsToSpendAllTraitPoints
    //ifTooMuchOrFewTraitPointsSpentThrowException
    //canSetRandomTraits
    //canGetAllEffectsAffectingAPlayer
};
