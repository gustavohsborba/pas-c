#ifndef _SYMBOL_ALREADY_INSTALLED_H
#define _SYMBOL_ALREADY_INSTALLED_H

#include <exception>
#include <sstream>

#include "frontend/Token.h"
#include "frontend/Symbol.h"

using std::exception;
using std::stringstream;

class SymbolAlreadyInstalled : public exception {

public:
	SymbolAlreadyInstalled(Token tok, Symbol sym) : tok(tok), sym(sym) {
	}

	virtual ~SymbolAlreadyInstalled() throw() {

	}

	const char * what() throw() {
		stringstream s;
		s << "Token " << tok.getValue() << " already installed as symbol ";
		return s.str().c_str();
	}

private:
	Token tok;
	Symbol sym;
};

#endif