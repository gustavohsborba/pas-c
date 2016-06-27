#ifndef _CONST_STR_EXPR_H
#define _CONST_STR_EXPR_H

#include <string>

#include "frontend/stmt/Statement.h"
#include "frontend/Symbol.h"

using std::string;

class ConstStrExpr : public Expression {
public:
	ConstStrExpr(CodeGenerator* gen, string value) : Expression(gen), value(value) {
		this->type = NATIVE_STR;
	}

	~ConstStrExpr(){

	}

	void emmit();

	inline string getValue(){ 
		return value;
	}

private:
	string value;

};


#endif