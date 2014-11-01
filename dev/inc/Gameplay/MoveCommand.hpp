
#ifndef MOVECOMMAND_HPP_
#define MOVECOMMAND_HPP_

#include "Gameplay/Command.hpp"
#include "GameMap/GameMap.hpp"
#include "MapElement/Fleet.hpp"
#include "Empire/CommonTypes.hpp"

namespace Gameplay
{

class MoveCommand : public Command
{
private:
	Coord origin;
	MapElementType elementToMove;
	Coord destination;
public:
	MoveCommand(Coord origin, MapElementType elementToMove, Coord destination);
	~MoveCommand();
	CommandResult executeCommand(GameMap::GameMap* map);
};

}

#endif /* MOVECOMMAND_HPP_ */
