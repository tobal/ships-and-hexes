
#include "PlayerConfig/Randomizer.hpp"

using namespace PlayerConfig;
using namespace std;

Randomizer::Randomizer()
{

}

Randomizer::~Randomizer()
{

}

intMap Randomizer::mapIndexesToTraitPoints(Traits traits)
{
	intMap indexPoints = intMap();
	for (size_t index = 0; index < traits.size(); ++index)
	{
		intPair p = intPair(index, traits.at(index).getTraitPoints());
		indexPoints.insert(p);
	}
	return indexPoints;
}

intPair Randomizer::chooseRandomTrait(intMap indexPoints)
{
	intMap::iterator picked = indexPoints.begin();
	srand(time(NULL));
	int randomIndex = rand() % indexPoints.size();
	advance(picked, randomIndex);
	return *picked;
}

vector<int> Randomizer::collectUnpickables(int points, intMap& indexPoints)
{
	vector<int> indexesToDelete = vector<int>();
	for (intMap::iterator it = indexPoints.begin(); it != indexPoints.end(); ++it)
	{
		if (it->second > points)
		{
			indexesToDelete.push_back(it->first);
		}
	}
	return indexesToDelete;
}

void Randomizer::eraseUnpickables(vector<int> indexesToDelete,
		intMap& indexPoints) {
	// eraseUnpickables
	for (vector<int>::iterator it = indexesToDelete.begin();
			it != indexesToDelete.end(); ++it) {
		indexPoints.erase(*it);
	}
}

void Randomizer::cleanUnpickableTraits(int points, intMap& indexPoints)
{
	vector<int> indexesToDelete = collectUnpickables(points, indexPoints);
	eraseUnpickables(indexesToDelete, indexPoints);
}

vector<int> Randomizer::pickTraits(Traits traits, int points)
{
	vector<int> pickedIndexes = vector<int>();
	intMap indexPoints = mapIndexesToTraitPoints(traits);
	while(points != 0)
	{
		intPair picked = chooseRandomTrait(indexPoints);
		int pickedIndex = picked.first;
		int pickedPoint = picked.second;
		if (points >= pickedPoint)
		{
			points -= pickedPoint;
			pickedIndexes.push_back(pickedIndex);
			indexPoints.erase(pickedIndex);
			cleanUnpickableTraits(points, indexPoints);
		}
		if(indexPoints.empty() && points > 0)
		{
			throw TraitRandomizerException("Trait points cannot be spent");
			break;
		}
	}
	return pickedIndexes;
}
