
#include "Gameplay/MoveCommand.hpp"

#include <stdexcept>
#include <iostream>

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
			int moves = 1;

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
					else
					{
						moves++;
						bool foundDestination = false;
						Coord iter = Coord(next.x, next.y);
						while(!foundDestination)
						{
							iter = map->getNextOnTrail(iter, destination);
							if(map->getHexOnCoord(iter)->hasFleet())
							{
								moves++;
							}
							else
							{
								foundDestination = true;
							}
						}
						next = iter;
						nextHex = map->getHexOnCoord(next);
					}
				}
			}

			try
			{
				fleet->move(moves);
			}
			catch(OutOfMovePointsException e)
			{
				return CANNOTMOVEFURTHER;
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
