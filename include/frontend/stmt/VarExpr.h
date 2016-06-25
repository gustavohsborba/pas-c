#ifndef _VAR_EXPR_H
#define _VAR_EXPR_H


#include "frontend/stmt/Statement.h"
#include "frontend/Symbol.h"

class VarExpr : public Expression {
public:
	VarExpr(CodeGenerator* gen, Symbol* symbol) : symbol(symbol) {

	}

	~VarExpr(){

	}

	void emmit();

private:
	Symbol* symbol;

};


#endif