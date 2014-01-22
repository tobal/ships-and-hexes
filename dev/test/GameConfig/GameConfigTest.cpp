
#include <cppunit/extensions/HelperMacros.h>

#include "GameConfig/PlayerSettings.hpp"
#include "GameConfig/GameSettings.hpp"
#include "GameConfig/GameConfigImpl.hpp"

using namespace CppUnit;
using namespace GameConfig;

class GameConfigTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( GameConfigTest );
    CPPUNIT_TEST(addPlayerMakesANewPlayer);
    CPPUNIT_TEST(getPlayerSettingsIsWorking);
    CPPUNIT_TEST(playerSettingsCanBeSet);
    CPPUNIT_TEST(gameSettingsCanBeSet);
    CPPUNIT_TEST_SUITE_END();

private:
    GameConfig::GameConfig* gameConf;

public:
    void setUp()
    {
    	gameConf = new GameConfigImpl();
    }
    void tearDown()
    {
    	delete gameConf;
    }

    void addPlayerMakesANewPlayer()
    {
    	gameConf->addPlayer("tobal", GREEN, false);
    	gameConf->addPlayer("vincenzo", RED, false);
    	CPPUNIT_ASSERT_EQUAL(2, gameConf->getNumberOfPlayers());
    }

    void getPlayerSettingsIsWorking()
    {
    	gameConf->addPlayer("tobal", GREEN, true);
    	gameConf->addPlayer("vincenzo", RED, true);
    	int num = gameConf->getNumberOfPlayers();
    	for (int i = 0; i < num; ++i)
    	{
			PlayerSettings playerSettings = gameConf->getPlayerSettings(i);
			CPPUNIT_ASSERT(playerSettings.controlledByAI);
		}
    }

    void playerSettingsCanBeSet()
    {
    	PlayerSettings playerSettings = PlayerSettings();
    	playerSettings.name = std::string("neuromanta");
    	playerSettings.color = YELLOW;
    	playerSettings.controlledByAI = false;

    	gameConf->addPlayer("tobal", GREEN, true);
    	gameConf->addPlayer("vincenzo", RED, true);
    	int index = 0;
    	gameConf->setPlayerSettings(index, playerSettings);

		PlayerSettings output = gameConf->getPlayerSettings(index);
		CPPUNIT_ASSERT(output.name.compare("neuromanta") == 0);
		CPPUNIT_ASSERT_EQUAL(YELLOW, output.color);
		CPPUNIT_ASSERT_EQUAL(false, output.controlledByAI);
    }

    void gameSettingsCanBeSet()
    {
    	GameSettings gameSettings = GameSettings();
    	gameSettings.width = 20;
    	gameSettings.height = 20;
    	gameSettings.density = 80;
    	gameSettings.randomTurns = true;
    	gameSettings.tipOfDay = false;
    	CPPUNIT_ASSERT( !(gameSettings == gameConf->getGameSettings()) );
    	gameConf->setGameSettings(gameSettings);
    	CPPUNIT_ASSERT( gameSettings == gameConf->getGameSettings() );
    }
};
