
#ifndef BUILDCOMMAND_HPP_
#define BUILDCOMMAND_HPP_

#include "Gameplay/Command.hpp"
#include "GameMap/GameMap.hpp"
#include "Empire/CommonTypes.hpp"
#include "MapElement/Building.hpp"

namespace Gameplay
{

class BuildCommand : public Command
{
private:
	Coord colony;
	int slot;
	MapElement::BuildingType bType;

public:
	BuildCommand(Coord colony, int slot, MapElement::BuildingType bType);
	~BuildCommand();
	CommandResult executeCommand(GameMap::GameMap* map);
};

}

#endif /* BUILDCOMMAND_HPP_ */
