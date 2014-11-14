
#include "Gameplay/ProduceCommand.hpp"

using namespace Gameplay;
using namespace MapElement;
using namespace GameMap;
using namespace std;

ProduceCommand::ProduceCommand(Coord coordinates, ProduceType produceType)
 : coordinates(coordinates), produceType(produceType)
{

}

ProduceCommand::~ProduceCommand()
{

}

CommandResult ProduceCommand::produceColonizer(GameMap::GameMap* map)
{
	Planet* planet = dynamic_cast<Planet*>(map->getHexOnCoord(coordinates)->getSpaceObject());
	if(planet != NULL)
	{
		float population = planet->getPopulation();
		if(population >= 2.0)
		{
			MapElementFactory factory = MapElementFactory(planet->getPlayerName());
			Fleet* colonizerFleet = factory.createFleet(0, 0, 1);
			if(map->getHexOnCoord(coordinates)->hasFleet())
			{
				if(map->getHexOnCoord(coordinates)->getFleet()->getPlayerName() == planet->getPlayerName())
				{
					map->getHexOnCoord(coordinates)->getFleet()->mergeFleet(colonizerFleet);
				}
				else
				{
					return PRODUCEFAILED;
				}
			}
			else
			{
				map->getHexOnCoord(coordinates)->addFleet(colonizerFleet);
			}
			planet->setPopulation(population - 1.0);
			return PRODUCESUCCESSFUL;
		}
	}
	return PRODUCEFAILED;
}

void ProduceCommand::removeColonizer(Hex* hex)
{
	hex->getFleet()->removeFleet(FleetCount(0, 0, 1));
	if (hex->getFleet()->fleetIsEmpty())
	{
		hex->destroyFleet();
	}
}

CommandResult ProduceCommand::produceColony(GameMap::GameMap* map)
{
	Planet* planet = dynamic_cast<Planet*>(map->getHexOnCoord(coordinates)->getSpaceObject());
	if(planet != NULL)
	{
		if (planet->getPlayerName() == string("nobody"))
		{
			Hex* hex = map->getHexOnCoord(coordinates);
			if(hasColonizer(hex))
			{
				planet->setPlayerName(hex->getFleet()->getPlayerName());
				planet->setPopulation(1.0f);

				removeColonizer(hex);
				return PRODUCESUCCESSFUL;
			}
		}
	}
	return PRODUCEFAILED;
}

bool ProduceCommand::hasColonizer(Hex* hex)
{
	if(hex->hasFleet())
	{
		if(hex->getFleet()->getFleetCount().colonizers >= 1)
		{
			return true;
		}
	}
	return false;
}

CommandResult ProduceCommand::produceSpaceStation(GameMap::GameMap* map)
{
	Hex* hex = map->getHexOnCoord(coordinates);
	if(hasColonizer(hex))
	{
		if(!hex->hasSpaceObject())
		{
			MapElementFactory factory = MapElementFactory(hex->getFleet()->getPlayerName());
			SpaceStation* station = factory.createStation();
			hex->addSpaceObject(station);
			removeColonizer(hex);
			return PRODUCESUCCESSFUL;
		}
	}
	return PRODUCEFAILED;
}

CommandResult ProduceCommand::executeCommand(GameMap::GameMap* map)
{
	switch(produceType)
	{
	case COLONIZERPROD:
		return produceColonizer(map);
	case COLONYPROD:
		return produceColony(map);
	case SPACESTATPROD:
		return produceSpaceStation(map);
	}

}

