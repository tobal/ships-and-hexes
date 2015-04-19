
#include "GFX/UIGFX/Button.hpp"

using namespace std;
using namespace UIGFX;
using namespace UserInterface;

Button::Button(orxVECTOR buttonPos,
			   string buttonPic,
			   string buttonHighlightPic,
			   ButtonId id)
{
	this->buttonPos = buttonPos;
	this->buttonPic = buttonPic;
	this->buttonHighlightPic = buttonHighlightPic;
	this->id = id;
}

Button::~Button()
{

}

orxVECTOR Button::getButtonPos()
{
	return this->buttonPos;
}

string Button::getButtonPic()
{
	return this->buttonPic;
}

string Button::getButtonHighlightPic()
{
	return this->buttonHighlightPic;
}

ButtonId Button::getButtonId()
{
	return id;
}
