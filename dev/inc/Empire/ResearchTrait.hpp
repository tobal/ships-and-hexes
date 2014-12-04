
#ifndef RESEARCHTRAIT_HPP_
#define RESEARCHTRAIT_HPP_

#include "Empire/CommonTypes.hpp"
#include <vector>

namespace Empire
{

struct TraitField
{
	TraitField(int level, ResearchFieldType field) :
		level(level), field(field) {}
	int level;
	ResearchFieldType field;
};

class ResearchTrait
{
private:
	std::vector<TraitField>* fields;

public:
	ResearchTrait();
	~ResearchTrait();
	int getNumOfFields() const;
	TraitField getField(int index);
};

typedef std::vector<ResearchTrait> ResearchTraits;

}

#endif /* RESEARCHTRAIT_HPP_ */
