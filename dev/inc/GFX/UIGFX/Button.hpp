
#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include <string>
#include <orx.h>
#include "GFXI/UserInterface/GameHUDGFXI.hpp"

namespace UIGFX
{

class Button
{
private:
	orxVECTOR buttonPos;
	std::string buttonPic;
	std::string buttonHighlightPic;
	UserInterface::ButtonId id;

public:
	Button(orxVECTOR buttonPos,
		   std::string buttonPic,
		   std::string buttonHighlightPic,
		   UserInterface::ButtonId id);
	~Button();
	UserInterface::ButtonId getButtonId();
};

}

#endif /* BUTTON_HPP_ */
