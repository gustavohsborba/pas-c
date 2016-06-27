#ifndef _WHILE_STMT_H
#define _WHILE_STMT_H

#include "frontend/stmt/Statement.h"

class WhileStmt : public ConditionalStmt {
public:
	WhileStmt(CodeGenerator* gen, Expression* expr, vector<Statement*> stmtList) : ConditionalStmt(gen, expr, stmtList) {

	}

	~WhileStmt() {

	}

	void emmit();

};

#endif
