
#include "Gameplay/MoveCommand.hpp"

using namespace Gameplay;
using namespace GameMap;
using namespace MapElement;

MoveCommand::MoveCommand(Coord origin, MapElementType elementToMove, Coord destination)
 : origin(origin), elementToMove(elementToMove), destination(destination)
{

}

MoveCommand::~MoveCommand()
{

}

CommandResult MoveCommand::executeCommand(GameMap::GameMap* map)
{
	if(elementToMove == FLEET)
	{
		Hex* originHex = map->getHexOnCoord(origin);
		if(originHex->hasFleet())
		{
			Fleet* fleet = originHex->getFleet();
			try
			{
				fleet->move(1);
			}
			catch(OutOfMovePointsException e)
			{
				return FAILURE;
			}
			originHex->removeFleet();
			Coord next = map->getNextOnTrail(origin, destination);
			Hex* nextHex = map->getHexOnCoord(next);
			nextHex->addFleet(fleet);
			origin = next;
			if(next == destination)
			{
				return DESTINATIONREACHED;
			}
			if(fleet->getMovePoints() == 0)
			{
				return OUTOFMOVEPOINTS;
			}
			return MOVEINPROGRESS;
		}
	}
	return FAILURE;
}
