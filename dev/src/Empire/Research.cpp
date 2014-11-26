
#include "Empire/Research.hpp"

using namespace Empire;
using namespace Gameplay;

Research::Research()
{
	for (int field = 0; field < NUM_OF_FIELDS; ++field)
	{
		this->field[field]->level = 1;
		this->field[field]->completePercent = 0;
	}
}

Research::~Research()
{

}

int Research::getFieldLevel(FieldType type)
{
	return field[type]->level;
}

int Research::getFieldCompletePercent(FieldType type)
{
	return field[type]->completePercent;
}

void Research::advanceFieldByResearchPoints(FieldType type, int researchPoints)
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
