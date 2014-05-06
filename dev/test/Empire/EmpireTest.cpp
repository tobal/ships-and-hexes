
#include <cppunit/extensions/HelperMacros.h>

#include "Empire/EmpireImpl.hpp"

using namespace CppUnit;
using namespace Empire;

class EmpireTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( EmpireTest );
    CPPUNIT_TEST(init);
    CPPUNIT_TEST_SUITE_END();

private:
    Empire::Empire* empire;

public:
    void setUp()
    {
    	empire = new EmpireImpl();
    }
    void tearDown()
    {
    	delete empire;
    }

    void init()
    {

    	// inject external interfaces (gamestate, gameconfig, research)
    	// request aggregated data of empire feats
    	// assert that data matches
    	CPPUNIT_ASSERT_EQUAL(1, 1);
    }

    // get global effects (mostly from anomalies)
};
