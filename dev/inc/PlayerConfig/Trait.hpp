
#ifndef TRAIT_HPP_
#define TRAIT_HPP_

#include <vector>

namespace PlayerConfig
{
// TODO: remove these two, replace with actual data classes
typedef int Effect;
// TODO: after replaced with classes, add more tests to test them

// TODO: put this to Empire package
typedef std::vector<Effect> Effects;

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

}

#endif /* TRAIT_HPP_ */
