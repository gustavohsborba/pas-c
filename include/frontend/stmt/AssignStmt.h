#ifndef _ASSIGN_STMT_H
#define _ASSIGN_STMT_H

#include "exception/TypeMismatch.h"

#include "frontend/stmt/Statement.h"
#include "frontend/Symbol.h"

class AssignStmt : public Statement {
public:
	AssignStmt(CodeGenerator* gen, Symbol* var, Expression *expr) : Statement(gen), var(var), expr(expr) {

		if(var->getType() != expr->getType())
			throw TypeMismatch();
	}

	~AssignStmt() {
		delete expr;
	}

	void emmit();

private:
	Symbol* var;
	Expression* expr;
};

#endif