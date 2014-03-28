
#include "PlayerConfig/PlayerConfigImpl.hpp"
#include "EffectMock.cpp"
#include <vector>

using namespace PlayerConfig;
using namespace Empire::Effect;
using namespace std;

void PlayerConfigImpl::constructTraits()
{
	// TODO: replace mock with actual effects
	// TODO: put this into a singleton
	Effect effect = EffectMock();
	allTraits->push_back(Trait(4).withEffect(effect).withEffect(effect));
	allTraits->push_back(Trait(3));
	allTraits->push_back(Trait(2).withEffect(effect));
	allTraits->push_back(Trait(2));
	allTraits->push_back(Trait(1).withEffect(effect).withEffect(effect).withEffect(effect));
	allTraits->push_back(Trait(2));
	allTraits->push_back(Trait(1));
	allTraits->push_back(Trait(2));
	allTraits->push_back(Trait(3));
	allTraits->push_back(Trait(2));
	allTraits->push_back(Trait(2));
	allTraits->push_back(Trait(2));
	allTraits->push_back(Trait(2));
	allTraits->push_back(Trait(1));
	allTraits->push_back(Trait(1));
	allTraits->push_back(Trait(1));
	allTraits->push_back(Trait(1));
	allTraits->push_back(Trait(2));
	allTraits->push_back(Trait(2));
	allTraits->push_back(Trait(1));
}

PlayerConfigImpl::PlayerConfigImpl()
 : race(new PlayerRace(HUMAN)), randomizer(new Randomizer()), allTraits(new Traits()), pickedIndexes(new vector<int>())
{
	constructTraits();
}

PlayerConfigImpl::~PlayerConfigImpl()
{
	delete race;
	delete randomizer;
	delete allTraits;
	delete pickedIndexes;
}

RaceType PlayerConfigImpl::getRaceType() const
{
	return race->getRaceType();
}

void PlayerConfigImpl::setRace(const RaceType raceType)
{
	race->setRace(raceType);
}

Credo PlayerConfigImpl::getCredo() const
{
	return race->getCredo();
}

PlanetType PlayerConfigImpl::getHomeworld() const
{
	return race->getHomeworldType();
}

void PlayerConfigImpl::setHomeworld(const PlanetType planetType)
{
	race->setHomeworld(planetType);
}

CredoType PlayerConfigImpl::getCredoType() const
{
	return race->getCredoType();
}

void PlayerConfigImpl::setCredo(const CredoType credoType)
{
	race->setCredo(credoType);
}

Traits PlayerConfigImpl::getAllTraits() const
{
	return *allTraits;
}

void PlayerConfigImpl::pickTraits(std::vector<int> picked) throw(TraitPointsNotSpentException)
{
	pickedIndexes->clear();
	for(vector<int>::iterator it = picked.begin(); it != picked.end(); ++it)
	{
		pickedIndexes->push_back(*it);
	}
	int traitPointsSpent = 0;
	for(vector<int>::iterator it = pickedIndexes->begin(); it != pickedIndexes->end(); ++it)
	{
		traitPointsSpent += allTraits->at(*it).getTraitPoints();
	}
	if(traitPointsSpent != race->getCredo().traitPoints)
	{
		throw TraitPointsNotSpentException("Too many or too few traits picked");
	}
}

Traits PlayerConfigImpl::getPickedTraits() const
{
	Traits traits = Traits();
	for(vector<int>::iterator it = pickedIndexes->begin(); it != pickedIndexes->end(); ++it)
	{
		traits.push_back(allTraits->at(*it));
	}
	return traits;
}

void PlayerConfigImpl::pickRandomTraits()
{
	vector<int> picked = randomizer->pickTraits(*allTraits, race->getCredo().traitPoints);
	this->pickTraits(picked);
}

Effects PlayerConfigImpl::getAllEffects() const
{
	Effects effects;
	Traits traits = getPickedTraits();
	for(Traits::iterator trait = traits.begin(); trait != traits.end(); ++trait)
	{
		Effects effectsOfTrait = trait->getEffects();
		effects.insert(effects.end(), effectsOfTrait.begin(), effectsOfTrait.end());
	}
	return effects;
}
