#ifndef _SYNTAX_ERROR_H
#define _SYNTAX_ERROR_H

#include <exception>
#include <sstream>

using std::stringstream;

class SyntaxError : public exception {

public:
	SyntaxError(long line, long column, Token token) : line(line), column(column), tok(token) {
	}

	virtual ~SyntaxError() throw() {

	}

	const char * what() throw() {
		
		stringstream s;
		
		s << "Sintax error found - Expected statement, but \'" << tok.getValue() << "\' found";
		
		return s.str().c_str();
	}

private:
	long line;
	long column;
	Token tok;
};



#endif
