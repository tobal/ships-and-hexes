
#ifndef TRAITPOINTSNOTSPENTEXCEPTION_HPP_
#define TRAITPOINTSNOTSPENTEXCEPTION_HPP_

#include <string>

class TraitPointsNotSpentException : public std::exception
{
public:
	TraitPointsNotSpentException(std::string m="exception!") : msg(m) {}
	virtual ~TraitPointsNotSpentException() throw() {}
	const char* what() const throw() { return msg.c_str(); }

private:
	std::string msg;
};

#endif /* TRAITPOINTSNOTSPENTEXCEPTION_HPP_ */
