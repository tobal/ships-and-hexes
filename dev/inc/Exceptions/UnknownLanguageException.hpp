
#ifndef UNKNOWNLANGUAGEEXCEPTION_HPP_
#define UNKNOWNLANGUAGEEXCEPTION_HPP_

class UnknownLanguageException : public std::exception
{
public:
	UnknownLanguageException(std::string m="exception!") : msg(m) {}
	virtual ~UnknownLanguageException() throw() {}
	const char* what() const throw() { return msg.c_str(); }

private:
	std::string msg;
};

#endif /* UNKNOWNLANGUAGEEXCEPTION_HPP_ */
