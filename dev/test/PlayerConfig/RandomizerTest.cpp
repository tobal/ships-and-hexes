
#include <cppunit/extensions/HelperMacros.h>

#include <vector>
#include "PlayerConfig/Randomizer.hpp"
#include "PlayerConfig/Trait.hpp"
#include "Exceptions/TraitRandomizerException.hpp"

using namespace CppUnit;
using namespace PlayerConfig;
using namespace std;

class RandomizerTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( RandomizerTest );
    CPPUNIT_TEST(randomizerReturnsIndexesOfTraitVector);
    CPPUNIT_TEST(randomizerPicksTraitsToSpendAllTraitPoints);
    CPPUNIT_TEST(throwExceptionWhenPointsCannotBeSpent);
    CPPUNIT_TEST_SUITE_END();

private:
    Randomizer* randomizer;

public:
    void setUp()
    {
    	randomizer = new Randomizer();
    }
    void tearDown()
    {
    	delete randomizer;
    }

    void randomizerReturnsIndexesOfTraitVector()
    {
    	vector<Trait> traits = vector<Trait>();
    	traits.push_back(Trait(1));
    	traits.push_back(Trait(1));
    	traits.push_back(Trait(1));
    	traits.push_back(Trait(1));
    	traits.push_back(Trait(1));
    	int points = 3;
    	vector<int> picked = randomizer->pickTraits(traits, points);
    	Trait trait = traits.at(picked.at(0));
    }

    void randomizerPicksTraitsToSpendAllTraitPoints()
    {
    	vector<Trait> traits = vector<Trait>();
    	traits.push_back(Trait(4));
    	traits.push_back(Trait(3));
    	traits.push_back(Trait(2));
    	traits.push_back(Trait(2));
    	traits.push_back(Trait(1));
    	traits.push_back(Trait(2));
    	traits.push_back(Trait(1));
    	traits.push_back(Trait(2));
    	traits.push_back(Trait(3));
    	traits.push_back(Trait(2));
    	traits.push_back(Trait(2));
    	traits.push_back(Trait(2));
    	traits.push_back(Trait(2));
    	traits.push_back(Trait(1));
    	traits.push_back(Trait(1));
    	traits.push_back(Trait(1));
    	traits.push_back(Trait(1));
    	traits.push_back(Trait(2));
    	traits.push_back(Trait(2));
    	traits.push_back(Trait(1));
    	int points = 10;
    	vector<int> picked = randomizer->pickTraits(traits, points);
    	int pointsSpent = 0;
    	for(vector<int>::iterator it = picked.begin(); it != picked.end(); ++it)
    	{
    		pointsSpent += traits.at(*it).getTraitPoints();
    	}
    	CPPUNIT_ASSERT_EQUAL(points, pointsSpent);
    	CPPUNIT_ASSERT(traits.size() != picked.size());
    }

    void throwExceptionWhenPointsCannotBeSpent()
    {
    	vector<Trait> traits = vector<Trait>();
    	traits.push_back(Trait(1));
    	traits.push_back(Trait(2));
    	int points = 5;
    	CPPUNIT_ASSERT_THROW(randomizer->pickTraits(traits, points), TraitRandomizerException);
    }
};
