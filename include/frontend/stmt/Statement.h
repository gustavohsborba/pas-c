#ifndef _STATEMENT_H
#define _STATEMENT_H

#include <set>

#include "frontend/CodeGenerator.h"

using std::set;

class Statement {
public:
	Statement(CodeGenerator* generator) : generator(generator) {

	}

	virtual ~Statement() = 0;

	virtual void emmit() = 0;

	int getNextInst();
	void setNextInst();

protected:
	CodeGenerator *generator;
	int nextInst;
};

class ConditionalStmt : public Statement {
public:
	ConditionalStmt(CodeGenerator* generator)  {
		Statement::Statement(generator);
	}

	virtual ~ConditionalStmt() = 0;
	virtual void emmit() = 0;

	void addAddressTrueSet(int address);
	void addAddressFalseSet(int address);

	set<int> getTrueSet();
	set<int> getFalseSet();

protected:
	set<int> trueSet;
	set<int> falseSet;
};

class Expression : public Statement {

public:
	Expression(CodeGenerator* generator) {
		Statement::Statement(generator);
	}

	
};

#endif