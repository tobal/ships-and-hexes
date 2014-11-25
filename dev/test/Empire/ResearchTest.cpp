
#include <cppunit/extensions/HelperMacros.h>

#include "Empire/Research.hpp"

using namespace CppUnit;
using namespace Empire;

class ResearchTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( ResearchTest );
    CPPUNIT_TEST(canGetResearchFieldLevels);
    CPPUNIT_TEST(canGetCompletePercentOfField);
    CPPUNIT_TEST_SUITE_END();

private:
    Research* research;

public:
    void setUp()
    {
    	research = new Research();
    }
    void tearDown()
    {
    	delete research;
    }

    void canGetResearchFieldLevels()
    {
    	FieldType empireField = EMPIRE;
    	int empireLevel = research->getFieldLevel(empireField);
    	CPPUNIT_ASSERT_EQUAL(1, empireLevel);
    }

    void canGetCompletePercentOfField()
    {
    	FieldType empireField = MILITARY;
    	int empireCompleteness = research->getFieldCompletePercent(empireField);
    	CPPUNIT_ASSERT_EQUAL(0, empireCompleteness);
    }

    void canAdvanceFieldByResearchPoints()
    {
    }

    void fieldsCanLevelUp()
    {
    }

    void canGetEffectAccordingToFieldAndLevel()
    {
    }

    void canGetResearchTraits()
    {
    }

    void canGetIfResearchTraitIsFulfilled()
    {
    }

    void canGetResearchTraitEffect()
    {
    }
};
