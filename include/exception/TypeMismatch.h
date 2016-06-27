#ifndef _TYPE_MISMATCH_H
#define _TYPE_MISMATCH_H

#include <exception>
#include <sstream>

using std::exception;
using std::stringstream;

class TypeMismatch : public exception {

public:
	TypeMismatch() {
	}

	virtual ~TypeMismatch() throw() {

	}

	const char * what() {

		return "Type mismatch";
	}

};

#endif