
#ifndef RANDOMIZER_HPP_
#define RANDOMIZER_HPP_

#include <cstdlib>
#include <algorithm>
#include "PlayerConfig/Trait.hpp"
#include "Exceptions/TraitRandomizerException.hpp"

namespace PlayerConfig
{

typedef std::vector<Trait> Traits;

// TODO: make this class static
class Randomizer
{
private:
	static const int threshold = 30;

	bool indexNotPicked(size_t i, std::vector<int>& pickedIndexes);
	void pickTrait(size_t index, Traits& traits, std::vector<int>& pickedIndexes, int& points);
	void pickRandomTraits(Traits& traits, std::vector<int>& pickedIndexes, int& points);

public:
	Randomizer();
	~Randomizer();
	std::vector<int> pickTraits(Traits traits, int points);
};

}

#endif /* RANDOMIZER_HPP_ */
