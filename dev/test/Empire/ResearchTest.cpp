
#include <cppunit/extensions/HelperMacros.h>

#include "Empire/Research.hpp"

using namespace CppUnit;
using namespace Empire;
using namespace Empire::Effect;

class ResearchTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( ResearchTest );
    CPPUNIT_TEST(canGetResearchFieldLevels);
    CPPUNIT_TEST(canGetCompletePercentOfField);
    CPPUNIT_TEST(canAdvanceFieldByResearchPoints);
    CPPUNIT_TEST(fieldsCanLevelUp);
    CPPUNIT_TEST(fieldsCantGetPastMaxLevel);
    CPPUNIT_TEST(canGetEffectAccordingToFieldAndLevel);
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
    	FieldType empireField = EMPIRE;
    	research->advanceFieldByResearchPoints(empireField, 10);
    	CPPUNIT_ASSERT_EQUAL(10, research->getFieldCompletePercent(empireField));
    }

    void fieldsCanLevelUp()
    {
    	FieldType empireField = EMPIRE;
    	research->advanceFieldByResearchPoints(empireField, 120);
    	CPPUNIT_ASSERT_EQUAL(2, research->getFieldLevel(empireField));
    	CPPUNIT_ASSERT_EQUAL(20, research->getFieldCompletePercent(empireField));
    }

    void fieldsCantGetPastMaxLevel()
    {
    	FieldType empireField = EMPIRE;
    	research->advanceFieldByResearchPoints(empireField, 920);
    	CPPUNIT_ASSERT_EQUAL(10, research->getFieldLevel(empireField));
    	CPPUNIT_ASSERT_EQUAL(0, research->getFieldCompletePercent(empireField));
    	research->advanceFieldByResearchPoints(empireField, 100);
    	CPPUNIT_ASSERT_EQUAL(10, research->getFieldLevel(empireField));
    	CPPUNIT_ASSERT_EQUAL(0, research->getFieldCompletePercent(empireField));
    }

    void canGetEffectAccordingToFieldAndLevel()
    {
    	FieldType empireField = EMPIRE;
    	research->advanceFieldByResearchPoints(empireField, 120);
    	Effect::Effect* researchEffect = research->getResearchEffect(empireField);
    	// TODO: refactor Effect inheritence
    	PlanetControlBonus* planetControl = dynamic_cast<PlanetControlBonus*>(researchEffect);
    	CPPUNIT_ASSERT(planetControl != NULL);
    	CPPUNIT_ASSERT_EQUAL(2 * 2, planetControl->getControlBonus());
    	delete researchEffect;
    }

    void canGetResearchTraits()
    {
    }

    void canGenerateRandomResearchTraits()
    {
    }

    void canGetIfResearchTraitIsFulfilled()
    {
    }

    void canGetResearchTraitEffect()
    {
    }
};
