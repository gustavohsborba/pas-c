
#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H

#include <string>

using std::string;

class Instruction {
public:
	Instruction() {

	}

	~Instruction() {

	}
};

class MoveInst : public Instruction {

};

class JumpInst : public Instruction {
public:
	int address;
};

class CondJumpInst : public Instruction{
public:
	int address;
	string condition;
};

#endif