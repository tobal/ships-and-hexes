
#include "Empire/Research.hpp"

using namespace Empire;
using namespace Empire::Effect;
using namespace Gameplay;

Research::Research()
{
	for (int field = 0; field < NUM_OF_FIELDS; ++field)
	{
		this->field[field]->level = 1;
		this->field[field]->completePercent = 0;
	}

	// TODO: generate
	traits = new ResearchTraits();
	traits->push_back(ResearchTrait());
	traits->push_back(ResearchTrait());
}

Research::~Research()
{

}

int Research::getFieldLevel(ResearchFieldType type)
{
	return field[type]->level;
}

int Research::getFieldCompletePercent(ResearchFieldType type)
{
	return field[type]->completePercent;
}

Effect::Effect* Research::getResearchEffect(ResearchFieldType type)
{
	switch(type)
	{
	case(EMPIRE):
		Effect::PlanetControlBonus* planetControl = new Effect::PlanetControlBonus();
		planetControl->setEffectByEmpireResearchLevel(field[type]->level);
		return planetControl;
	}
}

void Research::advanceFieldByResearchPoints(ResearchFieldType type, int researchPoints)
{
	// TODO: figure out the correct formula
	field[type]->completePercent += researchPoints;
	while(field[type]->completePercent >= 100)
	{
		field[type]->completePercent -= 100;
		field[type]->level += 1;
		if(field[type]->level >= GameplayConfig().research.maxResearchLevel)
		{
			field[type]->level = GameplayConfig().research.maxResearchLevel;
			field[type]->completePercent = 0;
		}
	}
}

ResearchTraits* Research::getResearchTraits()
{
	return traits;
}

int Research::getNumOfTraits() const
{
	return traits->size();
}

bool Research::isLevelRequirementMet(ResearchTrait trait, int fieldIdx)
{
	return trait.getField(fieldIdx).level
			> field[trait.getField(fieldIdx).field]->level;
}

bool Research::isTraitFulfilled(int index)
{
	ResearchTrait trait = traits->at(index);
	bool fulfilled = true;
	for (int fieldIdx = 0; fieldIdx < trait.getNumOfFields(); ++fieldIdx)
	{
		if (isLevelRequirementMet(trait, fieldIdx))
		{
			fulfilled = false;
		}
	}
	return fulfilled;
}
