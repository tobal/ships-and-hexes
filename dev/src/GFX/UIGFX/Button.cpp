
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

ButtonId Button::getButtonId()
{
	return id;
}
