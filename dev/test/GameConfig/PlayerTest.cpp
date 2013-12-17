
#include <cppunit/extensions/HelperMacros.h>

#include "GameConfig/Player.hpp"

using namespace CppUnit;
using namespace GameConfig;
using namespace std;

class PlayerTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( PlayerTest );
    CPPUNIT_TEST(playerSettingsCanBeSet);
    CPPUNIT_TEST(getPlayerConfigGivesPointerToPlayer);
    CPPUNIT_TEST_SUITE_END();

private:
    Player* player;

public:
    void setUp()
    {
    	player = new Player();
    }
    void tearDown()
    {
    	delete player;
    }

    void playerSettingsCanBeSet()
    {
    	string name = string("tobal");
    	player->setName(name);
    	CPPUNIT_ASSERT(name.compare( player->getName() ) == 0);
    	player->setColor(GREEN);
    	CPPUNIT_ASSERT_EQUAL(GREEN, player->getColor());
    	player->controlByAI(true);
    	CPPUNIT_ASSERT(player->isControlledByAI());
    }

    void getPlayerConfigGivesPointerToPlayer()
    {

    }
};
