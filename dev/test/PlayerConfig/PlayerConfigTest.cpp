
#include <cppunit/extensions/HelperMacros.h>

#include "PlayerConfig/PlayerConfigImpl.hpp"
#include "Exceptions/TraitPointsNotSpentException.hpp"

using namespace CppUnit;
using namespace PlayerConfig;
using namespace std;

class PlayerConfigTest : public TestFixture
{

	int countSpentTraitPoints(Traits pickedTraits)
	{
		int spentTraitPoints = 0;
		for (Traits::iterator it = pickedTraits.begin(); it != pickedTraits.end(); ++it)
		{
			spentTraitPoints += (*it).getTraitPoints();
		}
		return spentTraitPoints;
	}

	vector<int> pickTraitsToSpendPoints()
	{
		vector<int> picked;
	    picked.push_back(0);
	    picked.push_back(1);
	    picked.push_back(2);
	    picked.push_back(4);
	    return picked;
	}

    CPPUNIT_TEST_SUITE( PlayerConfigTest );
    CPPUNIT_TEST(canModifyBasicPlayerRaceSettings);
    CPPUNIT_TEST(canGetAllTraits);
    CPPUNIT_TEST(canSetTraitsToSpendAllTraitPoints);
    CPPUNIT_TEST(ifTooMuchOrFewTraitPointsSpentThrowException);
    CPPUNIT_TEST(canSetRandomTraits);
    CPPUNIT_TEST(canGetAllEffectsAffectingAPlayer);
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
    	CPPUNIT_ASSERT_EQUAL(AMAZON, config->getRaceType());
    	config->setHomeworld(LAVA);
    	CPPUNIT_ASSERT_EQUAL(LAVA, config->getHomeworld());
    	config->setCredo(WARMONGER);
    	CPPUNIT_ASSERT_EQUAL(WARMONGER, config->getCredoType());
    }

    void canGetAllTraits()
    {
    	Traits traits = config->getAllTraits();
    	CPPUNIT_ASSERT_EQUAL(size_t(20), traits.size());
    }

    void canSetTraitsToSpendAllTraitPoints()
    {
    	vector<int> picked = pickTraitsToSpendPoints();
    	config->pickTraits(picked);
    	Traits pickedTraits = config->getPickedTraits();
		int spentTraitPoints = countSpentTraitPoints(pickedTraits);
    	CPPUNIT_ASSERT_EQUAL(config->getCredo().traitPoints, spentTraitPoints);
    }

    void ifTooMuchOrFewTraitPointsSpentThrowException()
    {
    	vector<int> picked = pickTraitsToSpendPoints();
    	picked.push_back(6);
    	CPPUNIT_ASSERT_THROW(config->pickTraits(picked), TraitPointsNotSpentException);
    }

    void canSetRandomTraits()
    {
    	config->pickRandomTraits();
    	Traits pickedTraits = config->getPickedTraits();
		int spentTraitPoints = countSpentTraitPoints(pickedTraits);
    	CPPUNIT_ASSERT_EQUAL(config->getCredo().traitPoints, spentTraitPoints);
    }

    void canGetAllEffectsAffectingAPlayer()
    {
    	vector<int> picked = pickTraitsToSpendPoints();
    	config->pickTraits(picked);
    	Effects allEffects = config->getAllEffects();
    	CPPUNIT_ASSERT_EQUAL(size_t(6), allEffects.size());
    }
};
