
#include "Gameplay/ProduceCommand.hpp"

using namespace Gameplay;
using namespace MapElement;

ProduceCommand::ProduceCommand(Coord coordinates)
 : coordinates(coordinates)
{

}

ProduceCommand::~ProduceCommand()
{

}

CommandResult ProduceCommand::executeCommand(GameMap::GameMap* map)
{
	return FAILURE;
}

