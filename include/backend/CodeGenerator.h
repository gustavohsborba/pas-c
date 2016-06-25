#ifndef _CODE_GENERATOR_H
#define _CODE_GENERATOR_H

#include <string>

#include "backend/Instruction.h"

using std::string;

class Instruction;


class CodeGenerator {
public:
	CodeGenerator() {

	}

	~CodeGenerator() {

	}


	void emmit(Instruction* inst);

	int getCounter();

private:
	vector<Instruction*> code;
	int counter;
};

#endif