
#ifndef TRAIT_HPP_
#define TRAIT_HPP_

#include <vector>
#include "Empire/Effect/Effect.hpp"

namespace PlayerConfig
{

class Trait
{
private:
	int points;
	Empire::Effect::Effects effects;

public:
	Trait(int points);
	~Trait();
	Trait& withEffect(Empire::Effect::Effect effect);
	int getTraitPoints() const;
	Empire::Effect::Effects getEffects() const;
};

typedef std::vector<Trait> Traits;

}

#endif /* TRAIT_HPP_ */
