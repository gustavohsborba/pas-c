#ifndef _AND_EXPR_H
#define _AND_EXPR_H

#include "frontend/stmt/Statement.h"
#include "frontend/Symbol.h"
#include "frontend/Type.h"

/**
 * Generate code to int product. 
 */
class AndExpr : protected Expression {

public:
	AndExpr(CodeGenerator* gen, Expression *left, Expression *right) : Expression(gen), left(left), right(right) {
		if (left->getType() != right->getType() && left->getType() != NATIVE_INT) {
			throw "Erro de tipo porra!";
		}

		this->type = left->getType();
	}

	void emmit();

	~AndExpr() {
		delete left;
		delete right;
	}

private:
	Expression *left, *right;
};

#endif