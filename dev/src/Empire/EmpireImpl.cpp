
#include "Empire/EmpireImpl.hpp"

using namespace Empire;
using namespace GameMap;
using namespace Effect;
using namespace MapElement;
using namespace std;

EmpireImpl::EmpireImpl()
{

}

EmpireImpl::~EmpireImpl()
{

}

void EmpireImpl::aggregateEmpireEffectsForPlayer(GameMap::GameMap* map, EmpireEffects* effects, string playerName)
{
	Coords anomalyCoords = map->getObjects(ANOMALY);
	for(Coords::iterator anomalyCoord = anomalyCoords.begin(); anomalyCoord != anomalyCoords.end(); ++anomalyCoord)
	{
		Hex* hex = map->getHexOnCoord(*anomalyCoord);
		if(hex->hasFleet())
		{
			if(hex->getFleet()->getPlayerName() == playerName)
			{
				Anomaly* anomaly = dynamic_cast<Anomaly*>(hex->getSpaceObject());
				anomaly->setControl(hex->getFleet()->getFleetCount().fighters);
				effects->push_back(anomaly->getEffect());
			}
		}
	}
}
