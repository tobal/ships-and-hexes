
#ifndef CANNOTMERGESHIPSEXCEPTION_HPP_
#define CANNOTMERGESHIPSEXCEPTION_HPP_

#include <string>

class CannotMergeShipsException : public std::exception
{
public:
	CannotMergeShipsException(std::string m="exception!") : msg(m) {}
	virtual ~CannotMergeShipsException() throw() {}
	const char* what() const throw() { return msg.c_str(); }

private:
	std::string msg;
};

#endif /* CANNOTMERGESHIPSEXCEPTION_HPP_ */
