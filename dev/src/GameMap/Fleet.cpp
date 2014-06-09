
#include "GameMap/Fleet.hpp"

using namespace GameMap;
using namespace MapElement;

Fleet::Fleet(int fighters, int bombers, int colonizers)
{
	MapElementFactory factory = MapElementFactory("nobody");
	fighter = factory.createFighter(fighters);
	bomber = factory.createBomber(bombers);
	colonizer = factory.createColonizer(colonizers);
}

Fleet::~Fleet()
{

}

FleetCount Fleet::getFleetCount() const
{
	FleetCount ret;
	ret.fighters = fighter->getCount();
	ret.bombers = bomber->getCount();
	ret.colonizers = colonizer->getCount();
	return ret;
}
