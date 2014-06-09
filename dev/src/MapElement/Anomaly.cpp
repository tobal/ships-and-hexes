
#include "MapElement/Anomaly.hpp"

using namespace MapElement;
using namespace std;
using namespace Empire::Effect;

Anomaly::Anomaly(string playerName, AnomalyType type, AnomalySize size, EmpireEffect* effect)
	: SpaceObject(playerName), type(type), size(size), effect(effect), control(0)
{

}

Anomaly::~Anomaly()
{
	delete effect;
}

AnomalyType Anomaly::getType() const
{
	return type;
}

AnomalySize Anomaly::getSize() const
{
	return size;
}

int Anomaly::getControl() const
{
	return control;
}

void Anomaly::setControl(const int control)
{
	this->control = control;
}

EmpireEffect* Anomaly::getEffect() const
{
	effect->setEffectByShipControl(control);
	return effect;
}
