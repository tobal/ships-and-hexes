
#ifndef OUTOFMOVEPOINTSEXCEPTION_HPP_
#define OUTOFMOVEPOINTSEXCEPTION_HPP_

#include <string>

class OutOfMovePointsException : public std::exception
{
public:
	OutOfMovePointsException( std::string m = "exception!", int moved = 0, int movesRemained = 0 )
		: msg(m), moved(moved), movesRemained(movesRemained) {}
	virtual ~OutOfMovePointsException() throw() {}
	const char* what() const throw() { return msg.c_str(); }
	int getMoved() { return moved; }
	int getMovesRemained() { return movesRemained; }

private:
	std::string msg;
	int moved;
	int movesRemained;
};

#endif /* OUTOFMOVEPOINTSEXCEPTION_HPP_ */
