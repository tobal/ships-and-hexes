
#ifndef CANNOTBUILDEXCEPTION_HPP_
#define CANNOTBUILDEXCEPTION_HPP_

#include <string>

class CannotBuildException : public std::exception
{
public:
	CannotBuildException(std::string m="exception!") : msg(m) {}
	virtual ~CannotBuildException() throw() {}
	const char* what() const throw() { return msg.c_str(); }

private:
	std::string msg;
};


#endif /* CANNOTBUILDEXCEPTION_HPP_ */
