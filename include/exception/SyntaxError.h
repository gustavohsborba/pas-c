#ifndef _SYNTAX_ERROR_H
#define _SYNTAX_ERROR_H

#include <exception>
#include <sstream>

using std::stringstream;

class SyntaxError : public exception {

public:
	SyntaxError(long line, long column) : line(line), column(column) {
	}

	virtual ~SyntaxError() throw() {

	}

	const char * what() throw() {
		
		stringstream s;
		
		s << "Sintax error found";
		
		return s.str().c_str();
	}

private:
	long line;
	long column;
};



#endif
