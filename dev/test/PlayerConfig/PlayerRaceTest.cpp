
#include <cppunit/extensions/HelperMacros.h>

#include "PlayerConfig/PlayerRace.hpp"

using namespace CppUnit;
using namespace PlayerConfig;
using namespace std;

class PlayerRaceTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( PlayerRaceTest );
    CPPUNIT_TEST(settingRaceSetsDefaultRaceParameters);
    CPPUNIT_TEST(settingRaceParametersOnlySetsGivenParameter);
    CPPUNIT_TEST(canGetCredoAndItsContents);
    CPPUNIT_TEST_SUITE_END();

private:
    PlayerRace* race;

public:
    void setUp()
    {
    	race = new PlayerRace(HUMAN);
    }
    void tearDown()
    {
    	delete race;
    }

    void settingRaceSetsDefaultRaceParameters()
    {
    	CPPUNIT_ASSERT_EQUAL(HUMAN, race->getRaceType());
    	CPPUNIT_ASSERT_EQUAL(WATER, race->getHomeworldType());
    	CPPUNIT_ASSERT_EQUAL(JACKOFALL, race->getCredoType());
    	race->setRace(TENTACLE);
    	CPPUNIT_ASSERT_EQUAL(TENTACLE, race->getRaceType());
    	CPPUNIT_ASSERT_EQUAL(DESERT, race->getHomeworldType());
    	CPPUNIT_ASSERT_EQUAL(ALTERNATE, race->getCredoType());
    }

    void settingRaceParametersOnlySetsGivenParameter()
    {
    	CPPUNIT_ASSERT_EQUAL(HUMAN, race->getRaceType());
    	CPPUNIT_ASSERT_EQUAL(WATER, race->getHomeworldType());
    	CPPUNIT_ASSERT_EQUAL(JACKOFALL, race->getCredoType());
    	race->setHomeworld(DESERT);
    	race->setCredo(SCIENTIFIC);
    	CPPUNIT_ASSERT_EQUAL(HUMAN, race->getRaceType());
    	CPPUNIT_ASSERT_EQUAL(DESERT, race->getHomeworldType());
    	CPPUNIT_ASSERT_EQUAL(SCIENTIFIC, race->getCredoType());
    }

    void canGetCredoAndItsContents()
    {
    	Credo credo = race->getCredo();
    	CPPUNIT_ASSERT_EQUAL(JACKOFALL, credo.type);
    	CPPUNIT_ASSERT_EQUAL(10, credo.traitPoints);
    	race->setCredo(SCIENTIFIC);
    	credo = race->getCredo();
    	CPPUNIT_ASSERT_EQUAL(SCIENTIFIC, credo.type);
    	CPPUNIT_ASSERT_EQUAL(6, credo.traitPoints);
    }
};
