
#include "PlayerConfig/PlayerRace.hpp"

using namespace PlayerConfig;
using namespace std;

PlayerRace::PlayerRace(RaceType raceType)
{
	// TODO: put prototypes to separate class
	createCredoPrototypes();
	createRacePrototypes();
	race = racePrototypes->find(raceType)->second;
}

PlayerRace::~PlayerRace()
{

}

void PlayerRace::createCredoPrototypes()
{
	credoPrototypes = new CredoPrototypes();

	// TODO: replace these stubs with actual data
	Effects effectsStub = Effects();
	BuildingType buildingStub = 0;

	addCredoPrototype(EXPANSIONIST, 8, effectsStub, buildingStub);
	addCredoPrototype(WARMONGER, 7, effectsStub, buildingStub);
	addCredoPrototype(SCIENTIFIC, 6, effectsStub, buildingStub);
	addCredoPrototype(UNIFIED, 8, effectsStub, buildingStub);
	addCredoPrototype(JACKOFALL, 10, effectsStub, buildingStub);
	addCredoPrototype(ALTERNATE, 10, effectsStub, buildingStub);
}

void PlayerRace::addCredoPrototype(CredoType type, int traitPoints, Effects effects, BuildingType specialBuilding)
{
	Credo credo = Credo(type, traitPoints, effects, specialBuilding);
	CredoPair tmpPair = CredoPair(type, credo);
	credoPrototypes->insert(tmpPair);
}

void PlayerRace::createRacePrototypes()
{
	racePrototypes = new RacePrototypes();

	addRacePrototype(HUMAN, WATER, JACKOFALL);
	addRacePrototype(AMAZON, WATER, SCIENTIFIC);
	addRacePrototype(INSECTOID, DESERT, UNIFIED);
	addRacePrototype(TENTACLE, DESERT, ALTERNATE);
	addRacePrototype(SILICONITIS, LAVA, EXPANSIONIST);
	addRacePrototype(MECHANIZED, LAVA, WARMONGER);
}

void PlayerRace::addRacePrototype(RaceType type, PlanetType homeworld, CredoType credo)
{
	Race race = Race(type, homeworld, credo);
	RacePair tmpPair = RacePair(type, race);
	racePrototypes->insert(tmpPair);
}

RaceType PlayerRace::getRaceType() const
{
	return race.type;
}

PlanetType PlayerRace::getHomeworldType() const
{
	return race.homeworld;
}

CredoType PlayerRace::getCredoType() const
{
	return race.credo;
}

Credo PlayerRace::getCredo() const
{
	return credoPrototypes->find(race.credo)->second;
}

void PlayerRace::setRace(const RaceType raceType)
{
	race = racePrototypes->find(raceType)->second;
}

void PlayerRace::setHomeworld(const PlanetType homeworld)
{
	race.homeworld = homeworld;
}

void PlayerRace::setCredo(const CredoType credo)
{
	race.credo = credo;
}
