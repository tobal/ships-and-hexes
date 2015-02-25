
#include "GameState/GameStateImpl.hpp"

using namespace GameState;
using namespace GameMap;
using namespace GameConfig;
using namespace std;

GameStateImpl::GameStateImpl()
{

}

GameStateImpl::~GameStateImpl()
{

}

EmpireDetails GameStateImpl::getEmpireDetails()
{

}

GameMap::GameMap* GameStateImpl::generateMap()
{
	GameMapGenerator* generator;
	generator = new GameMapGenerator();
	Player player1 = Player("player1", RED, false);
	Player player2 = Player("player2", YELLOW, true);

	vector<int> picked = vector<int>();
	picked.push_back(0);
	picked.push_back(2);
	picked.push_back(3);
	picked.push_back(17);
	player1.getPlayerConfig()->pickTraits(picked);

	Players players = Players();
	players.push_back(player1);
	players.push_back(player2);

	GameMap::GameMap* map = generator->generateMap(Coord(25, 20), 40, players);
	return map;
}