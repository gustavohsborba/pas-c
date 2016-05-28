#ifndef _UNKNOWN_OPERATOR_H
#define _UNKNOWN_OPERATOR_H

#include <exception>
#include <sstream>

#include "frontend/Token.h"
#include "frontend/TokenType.h"

using std::exception;
using std::stringstream;


class UnknownOperator : public exception {

public:
	UnknownOperator(Token tok) : tok(tok) {
	}

	virtual ~UnknownOperator() throw() {

	}

	const char * what() throw() {
		
		stringstream s;
		
		s << "Token " << tok.getValue() << " is not an operator";
		
		return s.str().c_str();
	}

private:
	Token tok;
	MalformedType t;
};


#endif