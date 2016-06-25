#ifndef _SYMBOL_NOT_FOUND_H
#define _SYMBOL_NOT_FOUND_H

#include <exception>
#include <sstream>

#include "frontend/Token.h"

using std::exception;
using std::stringstream;

class SymbolNotFound : public exception {

public:
	SymbolNotFound(Token tok) : tok(tok) {
	}

	virtual ~SymbolNotFound() throw() {

	}

	const char * what() {
		stringstream s;
		s << "Identifier " << tok.getValue() << " not declared in this scope";
		return s.str().c_str();
	}

private:
	Token tok;
};

#endif