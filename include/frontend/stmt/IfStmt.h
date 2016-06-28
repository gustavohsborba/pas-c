#ifndef _IF_STMT_H
#define _IF_STMT_H

#include <vector>

#include "frontend/stmt/Statement.h"

using std::vector;

class IfStmt : public ConditionalStmt {
public:
	IfStmt(CodeGenerator* gen, Expression* expr, vector<Statement*> stmtList) : ConditionalStmt(gen, expr, stmtList) {

	} 

	~IfStmt() {

	}

	void emmit();
private:

	vector<Statement*> elseList;
};

#endif