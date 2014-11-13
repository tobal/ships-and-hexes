
#ifndef BUILDCOMMAND_HPP_
#define BUILDCOMMAND_HPP_

#include "Gameplay/Command.hpp"
#include "GameMap/GameMap.hpp"
#include "Empire/CommonTypes.hpp"

namespace Gameplay
{

class ProduceCommand : public Command
{
private:
	Coord coordinates;

public:
	ProduceCommand(Coord coordinates);
	~ProduceCommand();
	CommandResult executeCommand(GameMap::GameMap* map);
};

}

#endif /* BUILDCOMMAND_HPP_ */
