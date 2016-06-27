#include "frontend/Symbol.h"



string Symbol::getName() {
	return this->name;
}

void Symbol::setName(string name) {
	this->name = name;
}

long Symbol::getAddress() {
	return this->address;
}


void Symbol::setAddress(long address) {
	this->address = address;
}

VarType Symbol::getType() {
	return this->type;
}

void Symbol::setType(VarType type) {
	this->type = type;
}
