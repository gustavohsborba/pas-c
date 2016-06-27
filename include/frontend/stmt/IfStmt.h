#ifndef _IF_STMT_H
#define _IF_STMT_H

#include "frontend/stmt/Statement.h"

class IfStmt : public ConditionalStmt {
public:
	IfStmt(CodeGenerator* gen, Expression* expr, vector<Statement*> stmtList) : ConditionalStmt(gen, expr, stmtList) {

	} 

	~IfStmt() {

	}

	void emmit();

};

#endif