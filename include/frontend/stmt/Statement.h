#ifndef _STATEMENT_H
#define _STATEMENT_H

#include <set>
#include <vector>

#include "backend/CodeGenerator.h"
#include "frontend/Type.h"

using std::set;
using std::vector;

class Statement {
public:
	Statement() {
		generator = NULL;
	}

	Statement(CodeGenerator* generator) : generator(generator) {
	}

	~Statement() {}

	virtual void emmit() = 0;

	int getNextInst();
	void setNextInst();

protected:
	CodeGenerator *generator;
	int nextInst;
};

class Expression : public Statement {

public:
	Expression(CodeGenerator* generator) : Statement(generator){
		
	}

	inline ExprType getType() {
		return this->type;
	}

	inline void setType(ExprType type) {
		this->type = type;
	}

protected:
	ExprType type;
};

class ConditionalStmt : public Statement {
public:

	ConditionalStmt(CodeGenerator* generator, Expression* expr, vector<Statement*> stmtList) : Statement(generator), expr(expr), stmtList(stmtList) {
		if(expr->getType() != NATIVE_INT)
			throw "Erro de tipo";

	}

	~ConditionalStmt() {
		vector<Statement*>::iterator it = stmtList.begin();

		for(; it != stmtList.end(); ++it){
			delete *it;
		}

		stmtList.clear();
		delete expr;
	}

	void addAddressTrueSet(int address);
	void addAddressFalseSet(int address);

	set<int> getTrueSet();
	set<int> getFalseSet();

protected:
	set<int> trueSet;
	set<int> falseSet;
	Expression* expr;

	vector<Statement*> stmtList;
};


#endif