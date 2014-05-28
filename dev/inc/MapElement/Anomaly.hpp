
#ifndef ANOMALY_HPP_
#define ANOMALY_HPP_

#include <string>
#include "Empire/CommonTypes.hpp"
#include "MapElement/MapElement.hpp"
#include "Empire/Effect/EmpireEffect.hpp"

namespace MapElement
{

class Anomaly : public MapElement
{
private:
	AnomalyType type;
	AnomalySize size;
	Empire::Effect::EmpireEffect* effect;
	int control;

public:
	Anomaly(std::string playerName, AnomalyType type, AnomalySize size, Empire::Effect::EmpireEffect* effect);
	~Anomaly();
	AnomalyType getType() const;
	AnomalySize getSize() const;
	int getControl() const;
	void setControl(const int control);
	Empire::Effect::EmpireEffect* getEffect() const;
};

}

#endif /* ANOMALY_HPP_ */
