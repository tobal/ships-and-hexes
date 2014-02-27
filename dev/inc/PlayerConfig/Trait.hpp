
#ifndef TRAIT_HPP_
#define TRAIT_HPP_

#include <vector>
#include "Empire/CommonTypes.hpp"

namespace PlayerConfig
{

class Trait
{
private:
	int points;
	Effects effects;

public:
	Trait(int points);
	~Trait();
	Trait& withEffect(Effect effect);
	int getTraitPoints() const;
	Effects getEffects() const;
};

typedef std::vector<Trait> Traits;

}

#endif /* TRAIT_HPP_ */
