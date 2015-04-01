
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
	void (*action);

public:
	Button(ButtonId id, void (*action));
	~Button();
	void doAction();
};

}

#endif /* BUTTON_HPP_ */
