#ifndef _CONST_INT_EXPR_H
#define _CONST_INT_EXPR_H


#include "frontend/stmt/Statement.h"
#include "frontend/Symbol.h"

class ConstIntExpr : public Expression {
public:
	ConstIntExpr(CodeGenerator* gen, int value) : Expression(gen),  value(value) {
		this->type = NATIVE_INT;
	}

	~ConstIntExpr(){

	}

	void emmit();

	inline int getValue(){ 
		return value;
	}

private:
	int value;

};


#endif