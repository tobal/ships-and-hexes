
#include "GameMap/Fleet.hpp"

using namespace GameMap;
using namespace MapElement;
using namespace std;

Fleet::Fleet(int fighters, int bombers, int colonizers)
{
	MapElementFactory factory = MapElementFactory("nobody");
	fighter = factory.createFighter(fighters);
	bomber = factory.createBomber(bombers);
	colonizer = factory.createColonizer(colonizers);
}

Fleet::Fleet(FleetCount flc)
{
	MapElementFactory factory = MapElementFactory("nobody");
	fighter = factory.createFighter(flc.fighters);
	bomber = factory.createBomber(flc.bombers);
	colonizer = factory.createColonizer(flc.colonizers);
}

Fleet::~Fleet()
{
	delete fighter;
	delete bomber;
	delete colonizer;
}

Fighter* Fleet::getFighter() const
{
	return fighter;
}

Bomber* Fleet::getBomber() const
{
	return bomber;
}

Colonizer* Fleet::getColonizer() const
{
	return colonizer;
}

FleetCount Fleet::getFleetCount() const
{
	FleetCount ret;
	ret.fighters = fighter->getCount();
	ret.bombers = bomber->getCount();
	ret.colonizers = colonizer->getCount();
	return ret;
}

void Fleet::addFleet(Fleet* fleet)
{
	fighter->merge(fleet->getFighter());
	bomber->merge(fleet->getBomber());
	colonizer->merge(fleet->getColonizer());
}

void Fleet::removeFleet(FleetCount flc)
{
	fighter->destroy(flc.fighters);
	bomber->destroy(flc.bombers);
	colonizer->destroy(flc.colonizers);
}

int Fleet::getMovePoints() const
{
	vector<int> mps = vector<int>();
	if(fighter->getCount() > 0)
		mps.push_back(fighter->getMovePoints());
	if(bomber->getCount() > 0)
		mps.push_back(bomber->getMovePoints());
	if(colonizer->getCount() > 0)
		mps.push_back(colonizer->getMovePoints());
	return mps.empty() ? 0 : *(min_element(mps.begin(), mps.end()));
}

void Fleet::move(const int toMove) throw(OutOfMovePointsException)
{
	if(fighter->getCount() > 0)
		fighter->move(toMove);
	if(bomber->getCount() > 0)
		bomber->move(toMove);
	if(colonizer->getCount() > 0)
		colonizer->move(toMove);
}

Fleet* Fleet::splitFleet(FleetCount flc)
{
	FleetCount newFleetCount;
	newFleetCount.fighters = flc.fighters <= fighter->getCount() ? flc.fighters : fighter->getCount();
	newFleetCount.bombers = flc.bombers <= bomber->getCount() ? flc.bombers : bomber->getCount();
	newFleetCount.colonizers = flc.colonizers <= colonizer->getCount() ? flc.colonizers : colonizer->getCount();
	removeFleet(newFleetCount);
	Fleet* newFleet = new Fleet(newFleetCount);
	return newFleet;
}

void Fleet::resetMoves()
{
	fighter->resetMoves();
	bomber->resetMoves();
	colonizer->resetMoves();
}
