
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
			Coord next = map->getNextOnTrail(origin, destination);
			Hex* nextHex = map->getHexOnCoord(next);
			Fleet* fleet = originHex->getFleet();

			bool willMerge = false;
			Fleet* otherFleet = NULL;
			if(nextHex->hasFleet())
			{
				otherFleet = nextHex->getFleet();
				if(otherFleet->getPlayerName() == fleet->getPlayerName())
				{
					if(next == destination)
					{
						willMerge = true;
					}
				}
			}

			try
			{
				fleet->move(1);
			}
			catch(OutOfMovePointsException e)
			{
				return FAILURE;
			}
			originHex->removeFleet();
			if(willMerge)
			{
				fleet->mergeFleet(otherFleet);
				delete otherFleet;
			}
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
