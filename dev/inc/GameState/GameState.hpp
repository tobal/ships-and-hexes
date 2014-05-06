
#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_

#include "GameState/EmpireDetails.hpp"

namespace GameState
{

class GameState
{
public:
	GameState() {}
	virtual ~GameState() {}
	virtual EmpireDetails getEmpireDetails() {}
};

}

#endif /* GAMESTATE_HPP_ */
