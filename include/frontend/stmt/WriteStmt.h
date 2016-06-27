#ifndef _WRITE_STMT_H
#define _WRITE_STMT_H

#include "frontend/stmt/Statement.h"
#include "frontend/Symbol.h"

class WriteStmt : public Statement {
public:
	WriteStmt(CodeGenerator* gen, Expression *expr) : Statement(gen), expr(expr) {
	}

	~WriteStmt() {
		delete expr;
	}

	void emmit();

private:
	Expression* expr;
};

#endif