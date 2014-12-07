
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
    CPPUNIT_TEST(canGetResearchTraits);
    CPPUNIT_TEST(canGetIfResearchTraitIsFulfilled);
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
    	ResearchFieldType empireField = EMPIRE;
    	int empireLevel = research->getFieldLevel(empireField);
    	CPPUNIT_ASSERT_EQUAL(1, empireLevel);
    }

    void canGetCompletePercentOfField()
    {
    	ResearchFieldType empireField = MILITARY;
    	int empireCompleteness = research->getFieldCompletePercent(empireField);
    	CPPUNIT_ASSERT_EQUAL(0, empireCompleteness);
    }

    void canAdvanceFieldByResearchPoints()
    {
    	ResearchFieldType empireField = EMPIRE;
    	research->advanceFieldByResearchPoints(empireField, 10);
    	CPPUNIT_ASSERT_EQUAL(10, research->getFieldCompletePercent(empireField));
    }

    void fieldsCanLevelUp()
    {
    	ResearchFieldType empireField = EMPIRE;
    	research->advanceFieldByResearchPoints(empireField, 120);
    	CPPUNIT_ASSERT_EQUAL(2, research->getFieldLevel(empireField));
    	CPPUNIT_ASSERT_EQUAL(20, research->getFieldCompletePercent(empireField));
    }

    void fieldsCantGetPastMaxLevel()
    {
    	ResearchFieldType empireField = EMPIRE;
    	research->advanceFieldByResearchPoints(empireField, 920);
    	CPPUNIT_ASSERT_EQUAL(10, research->getFieldLevel(empireField));
    	CPPUNIT_ASSERT_EQUAL(0, research->getFieldCompletePercent(empireField));
    	research->advanceFieldByResearchPoints(empireField, 100);
    	CPPUNIT_ASSERT_EQUAL(10, research->getFieldLevel(empireField));
    	CPPUNIT_ASSERT_EQUAL(0, research->getFieldCompletePercent(empireField));
    }

    void canGetEffectAccordingToFieldAndLevel()
    {
    	ResearchFieldType empireField = EMPIRE;
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
    	CPPUNIT_ASSERT_EQUAL(2, research->getNumOfTraits());
    	ResearchTraits* traits = research->getResearchTraits();
    	CPPUNIT_ASSERT_EQUAL(2, traits->at(0).getNumOfFields());
    	CPPUNIT_ASSERT_EQUAL(EMPIRE, traits->at(0).getField(0).field);
    	CPPUNIT_ASSERT_EQUAL(6, traits->at(0).getField(0).level);
    	CPPUNIT_ASSERT_EQUAL(MILITARY, traits->at(0).getField(1).field);
    	CPPUNIT_ASSERT_EQUAL(6, traits->at(0).getField(1).level);
    	CPPUNIT_ASSERT_EQUAL(2, traits->at(1).getNumOfFields());
    	CPPUNIT_ASSERT_EQUAL(EMPIRE, traits->at(1).getField(0).field);
    	CPPUNIT_ASSERT_EQUAL(6, traits->at(1).getField(0).level);
    	CPPUNIT_ASSERT_EQUAL(MILITARY, traits->at(1).getField(1).field);
    	CPPUNIT_ASSERT_EQUAL(6, traits->at(1).getField(1).level);
    }

    // TODO: implement this feature
    void canGenerateRandomResearchTraits()
    {
    }

    void canGetIfResearchTraitIsFulfilled()
    {
    	ResearchTraits* traits = research->getResearchTraits();
    	CPPUNIT_ASSERT(! research->isTraitFulfilled(0));
    	research->advanceFieldByResearchPoints(EMPIRE, 500);
    	research->advanceFieldByResearchPoints(MILITARY, 500);
    	CPPUNIT_ASSERT(research->isTraitFulfilled(0));
    }

    void canGetResearchTraitEffect()
    {
    }
};
