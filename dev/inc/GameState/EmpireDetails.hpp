
#ifndef EMPIREDETAILS_HPP_
#define EMPIREDETAILS_HPP_

#include <vector>
#include "Empire/Effect/Effect.hpp"
#include "Empire/CommonTypes.hpp"

namespace GameState
{

struct Planet
{
	Empire::Effect::Effects buildingEffects;
	Empire::Effect::Effect planetTrait;
	int population;
	Empire::Effect::Effects miscellious;
};

typedef std::vector<Planet> Planets;

struct Anomaly
{
	AnomalyType type;
	int control;
};

typedef std::vector<Anomaly> Anomalies;

struct EmpireDetails
{
	Planets planets;
	int numOfSpaceStations;
	struct ships
	{
		int numOfColonyShips;
		int numOfFighters;
		int numOfBombers;
	};
	Anomalies anomalies;
};

}

#endif /* EMPIREDETAILS_HPP_ */
