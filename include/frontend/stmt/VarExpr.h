#ifndef _VAR_EXPR_H
#define _VAR_EXPR_H


#include "frontend/stmt/Statement.h"
#include "frontend/Symbol.h"

class VarExpr : public Expression {
public:
	VarExpr(CodeGenerator* gen, Symbol* symbol) : Expression(gen), symbol(symbol) {
		this->type = symbol->getType();
	}

	~VarExpr(){

	}

	void emmit();

private:
	Symbol* symbol;

};


#endif