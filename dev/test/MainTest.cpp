
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

using namespace CppUnit;

class testClass : public TestFixture
{
    CPPUNIT_TEST_SUITE( testClass );
    CPPUNIT_TEST(sanityTest);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() {}
    void tearDown() {}

    void sanityTest()
    {
        CPPUNIT_ASSERT(true);
    }
};

int main()
{
    TextUi::TestRunner runner;
    runner.addTest(testClass::suite());
    runner.run();
    return 0;
}
