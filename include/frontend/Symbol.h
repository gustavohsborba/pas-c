#ifndef _SYMBOL_H
#define _SYMBOL_H

#include <string>

#include "frontend/Type.h"

using std::string;

class Symbol {
public:
	
	Symbol() {
	}

	Symbol(string name, long address, VarType type) : name(name), address(address), type(type) {

	}

	~Symbol() {}

	string getName();
	void setName(string name);

	long getAddress();
	void setAddress(long address);

	VarType getType();
	void setType(VarType type);

private:
	string name;
	long address;
	VarType type;
};

#endif