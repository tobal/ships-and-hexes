
#include <cppunit/extensions/HelperMacros.h>

#include "PlayerConfig/Trait.hpp"
#include "Empire/Effect/Effect.hpp"
#include "EffectMock.cpp"

using namespace CppUnit;
using namespace PlayerConfig;
using namespace Empire::Effect;

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
    	Effect effect = EffectMock();
    	Trait trait = Trait(points)
    			.withEffect(effect)
    			.withEffect(effect);
    	CPPUNIT_ASSERT_EQUAL(points, trait.getTraitPoints());
    	Effects effects = trait.getEffects();
    	CPPUNIT_ASSERT_EQUAL((size_t)2, effects.size());
    }
};
