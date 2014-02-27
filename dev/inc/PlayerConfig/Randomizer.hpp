
#ifndef RANDOMIZER_HPP_
#define RANDOMIZER_HPP_

#include <cstdlib>
#include <time.h>
#include <vector>
#include <map>
#include "PlayerConfig/Trait.hpp"
#include "Exceptions/TraitRandomizerException.hpp"

namespace PlayerConfig
{

typedef std::map<int,int> intMap;
typedef std::pair<int,int> intPair;

// TODO: make this class static
class Randomizer
{
private:
	static const int threshold = 50;

	intMap mapIndexesToTraitPoints(Traits traits);
	intPair chooseRandomTrait(intMap indexPoints);
	void cleanUnpickableTraits(int points, intMap& indexPoints);
	std::vector<int> collectUnpickables(int points, intMap& indexPoints);
	void eraseUnpickables(std::vector<int> indexesToDelete, intMap& indexPoints);

public:
	Randomizer();
	~Randomizer();
	std::vector<int> pickTraits(Traits traits, int points);
};

}

#endif /* RANDOMIZER_HPP_ */
