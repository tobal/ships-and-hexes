
#include "Gameplay/BuildCommand.hpp"

using namespace Gameplay;

BuildCommand::BuildCommand(Coord colony) : colony(colony)
{

}

BuildCommand::~BuildCommand()
{

}

CommandResult BuildCommand::executeCommand(GameMap::GameMap* map)
{
	return FAILURE;
}

