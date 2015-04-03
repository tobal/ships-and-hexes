
#ifndef BUTTON_HPP_
#define BUTTON_HPP_

namespace UserInterface
{

enum ButtonId
{
	END_TURN
};

class Button
{
private:
	ButtonId id;

public:
	Button(ButtonId id);
	~Button();
	void doAction();
};

}

#endif /* BUTTON_HPP_ */
