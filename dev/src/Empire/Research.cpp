
#include "Empire/Research.hpp"

using namespace Empire;

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
