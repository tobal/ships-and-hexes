
#ifndef TRAITRANDOMIZEREXCEPTION_HPP_
#define TRAITRANDOMIZEREXCEPTION_HPP_

#include <string>

class TraitRandomizerException : public std::exception
{
public:
	TraitRandomizerException(std::string m="exception!") : msg(m) {}
	virtual ~TraitRandomizerException() throw() {}
	const char* what() const throw() { return msg.c_str(); }

private:
	std::string msg;
};

#endif /* TRAITRANDOMIZEREXCEPTION_HPP_ */
