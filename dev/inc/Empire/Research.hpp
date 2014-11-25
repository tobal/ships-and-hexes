
#ifndef RESEARCH_HPP_
#define RESEARCH_HPP_

namespace Empire
{

static const int NUM_OF_FIELDS = 2;

enum FieldType
{
	// TODO: fill with actual fields
	EMPIRE,
	MILITARY
};

struct Field
{
	int level;
	int completePercent;
};

class Research
{
private:
	Field* field[NUM_OF_FIELDS];

public:
	Research();
	~Research();
	int getFieldLevel(FieldType type);
	int getFieldCompletePercent(FieldType type);
};

}

#endif /* RESEARCH_HPP_ */
