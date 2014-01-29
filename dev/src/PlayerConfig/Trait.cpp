
#include "PlayerConfig/Trait.hpp"

using namespace PlayerConfig;

Trait::Trait(int points) : points(points)
{
	effects = Effects();
}

Trait::~Trait()
{

}

Trait& Trait::withEffect(Effect effect)
{
	effects.push_back(effect);
	return *this;
}

int Trait::getTraitPoints() const
{
	return points;
}

Effects Trait::getEffects() const
{
	return effects;
}
