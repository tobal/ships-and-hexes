
#include <cppunit/extensions/HelperMacros.h>

#include "Empire/Research.hpp"

using namespace CppUnit;
using namespace Empire;

class ResearchTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( ResearchTest );
    CPPUNIT_TEST(canGetResearchFieldLevels);
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
    }

    void canGetCompletePercentOfField()
    {
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
};
