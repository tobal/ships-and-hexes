
#ifndef RESEARCH_HPP_
#define RESEARCH_HPP_

#include "Empire/ResearchTrait.hpp"
#include "Empire/CommonTypes.hpp"
#include "Empire/Effect/Effect.hpp"
#include "Empire/Effect/PlanetControlBonus.hpp"
#include "Gameplay/GameplayConfig.hpp"

namespace Empire
{

static const int NUM_OF_FIELDS = 2;

struct Field
{
	int level;
	int completePercent;
};

class Research
{
private:
	Field* field[NUM_OF_FIELDS];
	ResearchTraits* traits;

public:
	Research();
	~Research();
	int getFieldLevel(ResearchFieldType type);
	int getFieldCompletePercent(ResearchFieldType type);
	Effect::Effect* getResearchEffect(ResearchFieldType type);
	int getNumOfTraits() const;
	ResearchTraits* getResearchTraits();
	void advanceFieldByResearchPoints(ResearchFieldType type, int researchPoints);
};

}

#endif /* RESEARCH_HPP_ */
