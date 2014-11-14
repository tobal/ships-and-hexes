
#ifndef COMMAND_HPP_
#define COMMAND_HPP_

#include "GameMap/GameMap.hpp"

namespace Gameplay
{

enum CommandResult
{
	SUCCESS,
	FAILURE,
	MOVEINPROGRESS,
	OUTOFMOVEPOINTS,
	DESTINATIONREACHED,
	CANNOTMOVEFURTHER,
	INCOLLISION,
	FLEETDESTROYED,
	BUILDSUCCESSFUL,
	DEMOLISTSUCCESSFUL,
	PRODUCESUCCESSFUL,
	PRODUCEFAILED
};

class Command
{
public:
	Command() {}
	virtual ~Command() {}
	virtual CommandResult executeCommand(GameMap::GameMap* map) = 0;
};

}

#endif /* COMMAND_HPP_ */
