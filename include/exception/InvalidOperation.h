#ifndef _INVALID_OPERATION_H
#define _INVALID_OPERATION_H

#include <exception>
#include <sstream>

using std::exception;
using std::stringstream;


class InvalidOperation : public exception {

public:
	InvalidOperation() {
	}

	virtual ~InvalidOperation() throw() {

	}

	const char * what() {
		return "Invalid operation";
	}

};

#endif