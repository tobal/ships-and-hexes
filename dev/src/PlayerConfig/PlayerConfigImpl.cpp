
#include "PlayerConfig/PlayerConfigImpl.hpp"

using namespace PlayerConfig;

void PlayerConfigImpl::constructTraits()
{
	traits->push_back(Trait(4));
	traits->push_back(Trait(3));
	traits->push_back(Trait(2));
	traits->push_back(Trait(2));
	traits->push_back(Trait(1));
	traits->push_back(Trait(2));
	traits->push_back(Trait(1));
	traits->push_back(Trait(2));
	traits->push_back(Trait(3));
	traits->push_back(Trait(2));
	traits->push_back(Trait(2));
	traits->push_back(Trait(2));
	traits->push_back(Trait(2));
	traits->push_back(Trait(1));
	traits->push_back(Trait(1));
	traits->push_back(Trait(1));
	traits->push_back(Trait(1));
	traits->push_back(Trait(2));
	traits->push_back(Trait(2));
	traits->push_back(Trait(1));
}

PlayerConfigImpl::PlayerConfigImpl() : race(new PlayerRace(HUMAN)), randomizer(new Randomizer()), traits(new Traits())
{
	constructTraits();
}

PlayerConfigImpl::~PlayerConfigImpl()
{
	delete race;
	delete randomizer;
	delete traits;
}

RaceType PlayerConfigImpl::getRace() const
{
	return race->getRaceType();
}

void PlayerConfigImpl::setRace(const RaceType raceType)
{
	race->setRace(raceType);
}

PlanetType PlayerConfigImpl::getHomeworld() const
{
	return race->getHomeworldType();
}

void PlayerConfigImpl::setHomeworld(const PlanetType planetType)
{
	race->setHomeworld(planetType);
}

CredoType PlayerConfigImpl::getCredo() const
{
	return race->getCredoType();
}

void PlayerConfigImpl::setCredo(const CredoType credoType)
{
	race->setCredo(credoType);
}
