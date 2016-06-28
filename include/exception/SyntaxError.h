#ifndef _SYNTAX_ERROR_H
#define _SYNTAX_ERROR_H

#include <exception>
#include <sstream>

#include "frontend/Token.h"

using std::stringstream;
using std::exception;

class SyntaxError : public exception {

public:
	SyntaxError(long line, long column, long mask, Token token) : line(line), column(column), mask(mask), tok(token) {
	}

	virtual ~SyntaxError() throw() {

	}

	const char * what() throw() {
		
		stringstream s;
        vector<TokenType> tokens = unmask(mask);
		
		s << "Sintax error found - Expected ";
        for(int i = 0; i < tokens.size(); ++i) {
            s << tok_name(tokens[i]) << ", ";
        }

        s << " but \'" << tok.getValue() << "\' found";
		
		return s.str().c_str();
	}

private:
	long line;
	long column;
	long mask;
	Token tok;
};



#endif