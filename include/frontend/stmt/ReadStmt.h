#ifndef _READ_STMT_H
#define _READ_STMT_H

#include <typeinfo>

#include "frontend/stmt/Statement.h"
#include "frontend/stmt/VarExpr.h"
#include "frontend/Symbol.h"

class ReadStmt : public Statement {
public:
	ReadStmt(CodeGenerator* gen, Symbol *var) : Statement(gen), var(var) {
	}

	~ReadStmt(){
	}

	void emmit();

private:
	Symbol* var;
};

#endif