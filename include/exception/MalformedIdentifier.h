#ifndef _MALFORMED_IDENTIFIER_H
#define _MALFORMED_IDENTIFIER_H

#include <exception>
#include <sstream>

#include "frontend/Token.h"
#include "frontend/TokenType.h"

using std::exception;
using std::stringstream;


typedef enum MalformedType{
	UNKNOWN_CHARACTER_SEQUENCE,
	IDENTIFIER_EXCEEDED_SIZE
} MalformedType;


class MalformedIdentifier : public exception {

public:
	MalformedIdentifier(Token tok, MalformedType t) : tok(tok), t(t) {
	}

	virtual ~MalformedIdentifier() throw() {

	}

	const char * what() throw() {
		stringstream s;

		switch (t){
			case UNKNOWN_CHARACTER_SEQUENCE:
				s << "Identifier " << tok.getValue() << " has no match with language structure.";
				break;
			case IDENTIFIER_EXCEEDED_SIZE:
				s << "Identifier " << tok.getValue() << " exceed the maximum size of " << MAX_IDENTIFIER_SIZE << " characters";
				break;
		}

		return s.str().c_str();
	}

private:
	Token tok;
	MalformedType t;
};




#endif