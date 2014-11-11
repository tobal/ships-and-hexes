
#ifndef BUILDCOMMAND_HPP_
#define BUILDCOMMAND_HPP_

#include "Gameplay/Command.hpp"
#include "GameMap/GameMap.hpp"
#include "Empire/CommonTypes.hpp"

namespace Gameplay
{

class BuildCommand : public Command
{
private:
	Coord colony;
public:
	BuildCommand(Coord colony);
	~BuildCommand();
	CommandResult executeCommand(GameMap::GameMap* map);
};

}

#endif /* BUILDCOMMAND_HPP_ */
