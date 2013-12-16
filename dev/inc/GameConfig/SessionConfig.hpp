
#ifndef SESSIONCONFIG_HPP_
#define SESSIONCONFIG_HPP_

namespace GameConfig
{

class SessionConfig
{
private:
	bool randomTurns;
	bool tipOfDay;

public:
	SessionConfig();
	~SessionConfig();
	bool getRandomTurns() const;
	bool getTipOfDay() const;
	void setRandomTurns(const bool randomTurns);
	void setTipOfDay(const bool tipOfDay);
};

}

#endif /* SESSIONCONFIG_HPP_ */
