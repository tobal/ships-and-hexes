
#include <cppunit/extensions/HelperMacros.h>

#include "PlayerConfig/Trait.hpp"

using namespace CppUnit;
using namespace PlayerConfig;

class TraitTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( TraitTest );
    CPPUNIT_TEST(traitDataClassCanBeCreated);
    CPPUNIT_TEST(traitDataClassCanBeCreatedWithEffects);
    CPPUNIT_TEST_SUITE_END();

public:

    void traitDataClassCanBeCreated()
    {
    	int points = 4;
    	Trait trait = Trait(points);
    	CPPUNIT_ASSERT_EQUAL(points, trait.getTraitPoints());
    }

    void traitDataClassCanBeCreatedWithEffects()
    {
    	int points = -3;
    	Effect effect = 100;
    	Trait trait = Trait(points)
    			.withEffect(effect)
    			.withEffect(effect);
    	CPPUNIT_ASSERT_EQUAL(points, trait.getTraitPoints());
    	Effects effects = trait.getEffects();
    	for(Effects::iterator it = effects.begin(); it != effects.end(); ++it)
    	{
        	CPPUNIT_ASSERT_EQUAL(effect, *it);
    	}
    }
};
