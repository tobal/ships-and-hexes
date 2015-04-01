
#include "GFXI/UserInterface/Button.hpp"

using namespace UserInterface;

Button::Button(ButtonId id, void (*action)) : id(id), action(action)
{

}

Button::~Button()
{

}

void Button::doAction()
{
//	this->action();
}
