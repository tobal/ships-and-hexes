
#ifndef PRODUCECOMMAND_HPP_
#define PRODUCECOMMAND_HPP_

#include "Gameplay/Command.hpp"
#include "GameMap/GameMap.hpp"
#include "GameMap/Hex.hpp"
#include "Empire/CommonTypes.hpp"
#include <string>

namespace Gameplay
{

enum ProduceType
{
	COLONIZERPROD,
	COLONYPROD,
	SPACESTATPROD
};

class ProduceCommand : public Command
{
private:
	Coord coordinates;
	ProduceType produceType;
	CommandResult produceColonizer(GameMap::GameMap* map);
	CommandResult produceColony(GameMap::GameMap* map);
	CommandResult produceSpaceStation(GameMap::GameMap* map);
	bool hasColonizer(GameMap::Hex* hex);
	void removeColonizer(GameMap::Hex* hex);

public:
	ProduceCommand(Coord coordinates, ProduceType produceType);
	~ProduceCommand();
	CommandResult executeCommand(GameMap::GameMap* map);
};

}

#endif /* PRODUCECOMMAND_HPP_ */
