
#include "Empire/ResearchTrait.hpp"

using namespace Empire;
using namespace std;

ResearchTrait::ResearchTrait()
{
	fields = new vector<TraitField>();

	// TODO: generate fields
	fields->push_back(TraitField(6, EMPIRE));
	fields->push_back(TraitField(6, MILITARY));
}

ResearchTrait::~ResearchTrait()
{

}

int ResearchTrait::getNumOfFields() const
{
	return fields->size();
}

TraitField ResearchTrait::getField(int index)
{
	return fields->at(index);
}
