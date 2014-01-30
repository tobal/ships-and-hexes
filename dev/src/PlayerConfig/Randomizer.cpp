
#include "PlayerConfig/Randomizer.hpp"

using namespace PlayerConfig;
using namespace std;

Randomizer::Randomizer()
{

}

Randomizer::~Randomizer()
{

}

bool Randomizer::indexNotPicked(size_t index, vector<int>& pickedIndexes)
{
	return find(pickedIndexes.begin(), pickedIndexes.end(), index)
			== pickedIndexes.end();
}

void Randomizer::pickTrait(size_t index, Traits& traits,
		vector<int>& pickedIndexes, int& points)
{
	Trait trait = traits.at(index);
	// TODO: randomize when not running tests
	if ((rand() % 100) < threshold)
	{
		pickedIndexes.push_back(index);
		points -= trait.getTraitPoints();
	}
}

void Randomizer::pickRandomTraits(Traits& traits, vector<int>& pickedIndexes, int& points)
{
	for (size_t index = 0; index < traits.size(); ++index)
	{
		if (indexNotPicked(index, pickedIndexes))
		{
			pickTrait(index, traits, pickedIndexes, points);
		}
		if (points == 0)
		{
			break;
		}
	}
}

vector<int> Randomizer::pickTraits(Traits traits, int points)
{
	vector<int> pickedIndexes = vector<int>();
	while (points != 0)
	{
		if(pickedIndexes.size() < traits.size())
		{
			pickRandomTraits(traits, pickedIndexes, points);
		}
		else
		{
			throw TraitRandomizerException("Trait points cannot be spent");
			break;
		}
	}
	return pickedIndexes;
}
